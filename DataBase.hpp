#ifndef DATABASE_
#define DATABASE_


#include "Contact.hpp"
#include <map>
#include <fstream>
#include <sstream>
#include <string>


class DataBase{
  public:
    DataBase(std::map<std::string, Contact> & contact_list, std::string filename){
    //DataBase(std::string filename){
      std::fstream data(filename);

      std::string db_line;
      while(getline(data, db_line)){
        std::string first_name, last_name, contact_info;

        std::stringstream contact_string(db_line);
        getline(contact_string, first_name, ' ');
        getline(contact_string, last_name,';');
        std::vector<PhoneNumber> temp;
        while(getline(contact_string, contact_info,'|')){
          std::stringstream phone_number_string(contact_info);
          std::string phone, type;
          getline(phone_number_string, phone,'/');
          getline(phone_number_string, type, '/');
          PhoneNumber num = PhoneNumber(phone, type);
          temp.push_back(num);
        }
        Contact temp2 = Contact(first_name, last_name);
        for(PhoneNumber i : temp){
          temp2.addNumber(i);
        }
        contact_list[first_name] = temp2;
        std::cout<<temp2;
      }
    }

};

#endif
