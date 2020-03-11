#ifndef CONTACT_APPLICATION_
#define CONTACT_APPLICATION_

#include "DataBase.hpp"

class ContactApplication{
  private:
    std::list<Contact> contact_list_;
    DataBase database_;

  public:
    ContactApplication(){
      database_ = DataBase();
      database_.FileToList(contact_list_);
    }

    void print(){
      std::cout<<*this;
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
