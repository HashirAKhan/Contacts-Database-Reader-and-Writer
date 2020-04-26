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

  public:
    ContactApplication(){
      database_ = DataBase();
      database_.FileToList(contact_list_);
    }

    void print(){
      std::cout<<*this;
    }
    bool removeNum(std::string str){
      return removeNumber(PhoneNumber(str, ""));
    }

    bool removeCont(std::string name){
      return removeContact(name);
    }

    bool addnum(Contact number){
      return addNumber(number);
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
