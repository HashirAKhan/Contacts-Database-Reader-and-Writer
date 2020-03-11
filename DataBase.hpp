#ifndef DATABASE_
#define DATABASE_


#include "Contact.hpp"
#include <list>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>


class DataBase{
  public:
    DataBase(){
      file_name_ = "DataBase.txt";
    }

    void FileToList(std::list<Contact> & contact_list){
    //DataBase(std::string filename){
      std::fstream data(file_name_);

      std::string db_line;
      while(getline(data, db_line)){
        std::string first_name, last_name, phone, type;

        std::stringstream contact_string(db_line);
        getline(contact_string, first_name, ' ');
        getline(contact_string, last_name,';');
        getline(contact_string, phone, '/');
        getline(contact_string, type, '|');
        Contact temp = Contact(first_name, last_name, PhoneNumber(phone, type));
        addContact(contact_list , temp);

      }
      data.close();
    }

    void addContact(std::list<Contact> & contact_list, Contact contact){
      std::list<Contact>::iterator it;
      for(it = contact_list.begin(); it != contact_list.end(); it++){
        if(it->getFullName() == contact.getFullName()){
          it->addNumber(contact.getPhoneNumbers()[0]);
          return;
        }
        if(it->getFullName()>contact.getFullName()){
          break;
        }
      }
      contact_list.insert(it, contact);
    }


  private:
    std::string file_name_;


};

#endif
