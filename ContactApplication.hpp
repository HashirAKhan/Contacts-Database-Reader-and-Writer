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

    friend std::ostream &operator<<(std::ostream &out, const ContactApplication &contact_application);


};
std::ostream &operator<<(std::ostream &out, const ContactApplication &contact_application){
  for(Contact i : contact_application.contact_list_){
    out<<i;
  }
  return out;
}

#endif
