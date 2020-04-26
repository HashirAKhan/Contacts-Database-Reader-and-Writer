#ifndef CONTACT_APPLICATION_
#define CONTACT_APPLICATION_

#include "DataBase.hpp"

class ContactApplication{
  private:
    std::list<Contact> contact_list_;
    DataBase database_;

    bool removeNumber(PhoneNumber number){
      for(std::list<Contact>::iterator i = contact_list_.begin(); i != contact_list_.end(); i++){
        if(i->removeNumber(number)){
          database_.removeNumber(number);
          return true;
        }
      }
      return true;

    }

    bool removeContact(std::string name){
      for(std::list<Contact>::iterator i = contact_list_.begin(); i != contact_list_.end(); i++){
        if(i->getFullName() == name){
          database_.removeContact(name);
          contact_list_.erase(i);
          return true;
        }
      }
      return true;
    }


    bool addContact(Contact contact){
      std::list<Contact>::iterator it;
      for(it = contact_list_.begin(); it != contact_list_.end(); it++){
        if(it->getFullName() == contact.getFullName()){
          return it->addNumber(contact.getPhoneNumbers()[0]);
        }
        if(it->getFullName()>contact.getFullName()){
          break;
        }
      }
      contact_list_.insert(it, contact);
      return true;
    }

    bool addNumber (Contact contact){
      if(addContact(contact)){
        database_.addNumber(contact);
        return true;
      }
      return false;
    }

    bool checkNum(std::string input, int options){
      int num = stoi(input);
      return (num < options && num > 0);
    }

    void mainMenu(){
      bool run = true;

      while(run){
        std::cout<<"Contact Application\n";
        std::cout<<"\t1. Show Contact List\n";
        std::cout<<"\t2. Add Contact or Number";
        std::cout<<"\t3. Delete Contact or Number"\n;
        std::cout<<"\t4. Exit Application"\n\n;
        std::string input;
        do{
          std::cout<<"\tPlease select and option(1-4): ";
          cin>>input;
        } while (validnum(input,4));


      }
    }

  public:
    ContactApplication(){
      database_ = DataBase();
      database_.FileToList(contact_list_);
    }

    void run(){
      system("clear");
      mainMenu();
    }


    friend std::ostream &operator<<(std::ostream &out, const ContactApplication &contact_application);


};
std::ostream &operator<<(std::ostream &out, const ContactApplication &contact_application){
  for(Contact i : contact_application.contact_list_){
    out<<i;
  }
  return out;
}

#endif
