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

      std::string db_line;
      std::ifstream data(file_name_);
      while(getline(data, db_line)){
        std::string first_name, last_name, phone, type;

        std::stringstream contact_string(db_line);
        getline(contact_string, first_name, ' ');
        getline(contact_string, last_name,';');
        getline(contact_string, phone, '/');
        getline(contact_string, type, '|');
        Contact temp = Contact(first_name, last_name, PhoneNumber(phone, type));
        addContactList(contact_list , temp);

      }
      data.close();
    }

    bool removeNumber(PhoneNumber number){
      bool del = false;
      std::string line;
      // open input file
      std::ifstream in(file_name_);

        // now open temp output file
      std::ofstream out("outfile.txt");
      // loop to read/write the file.  Note that you need to add code here to check
      // if you want to write the line
      while( getline(in,line) )
      {
        std::stringstream contact_string(line);
        std::string phone;
        getline(contact_string, phone, ';');
        getline(contact_string, phone, '/');
        if(stol(phone) != number.getNumber())
          out << line << "\n";
        else
          del = true;
      }
      in.close();
      out.close();
      // delete the original file
      std::remove("infile.txt");
      // rename old to new
      std::rename("outfile.txt","database.txt");
      return del;
    }

    bool removeContact(std::string name){
      bool del = false;
      std::string line;
      // open input file
      std::ifstream in(file_name_);

        // now open temp output file
      std::ofstream out("outfile.txt");
      // loop to read/write the file.  Note that you need to add code here to check
      // if you want to write the line
      while( getline(in,line) )
      {
        std::stringstream contact_string(line);
        std::string fullname;
        getline(contact_string, fullname, ';');
        if(fullname != name)
          out << line << "\n";
        else
          del = true;
      }
      in.close();
      out.close();
      // delete the original file
      std::remove("database.txt");
      // rename old to new
      std::rename("outfile.txt","database.txt");
      return del;
    }

    void addNumber(Contact contact){
      std::string line;
      // open input file
      std::ifstream in(file_name_);

        // now open temp output file
      std::ofstream out("outfile.txt");
      // loop to read/write the file.  Note that you need to add code here to check
      // if you want to write the line
      while( getline(in,line) )
      {
          out << line << "\n";
      }
      out<<contact.getFullName()<<";"<<contact.getPhoneNumbers()[0].getNumber()
      <<"/"<<contact.getPhoneNumbers()[0].getType()<<"|\n";

      in.close();

      out.close();
      // delete the original file
      std::remove("database.txt");
      // rename old to new
      std::rename("outfile.txt","database.txt");
    }




  private:


    bool addContactList(std::list<Contact> & contact_list, Contact contact){
      std::list<Contact>::iterator it;
      for(it = contact_list.begin(); it != contact_list.end(); it++){
        if(it->getFullName() == contact.getFullName()){
          return it->addNumber(contact.getPhoneNumbers()[0]);
        }
        if(it->getFullName()>contact.getFullName()){
          break;
        }
      }
      contact_list.insert(it, contact);
      return true;
    }

    std::string file_name_;

};

#endif
