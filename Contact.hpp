#ifndef CONTACT_
#define CONTACT_

#include "PhoneNumber.hpp"
#include <vector>

class Contact{
  private:
    std::string full_name_;
    std::string first_name_;
    std::string last_name_;
    std::vector<PhoneNumber> phone_numbers_;

  public:
    Contact(){
      full_name_ = "";
      first_name_ = "";
      last_name_ = "";
    }

    Contact(std::string first_name, std::string last_name){
      first_name_ = first_name;
      last_name_ = last_name;
      full_name_ = first_name_ + last_name_;
    }

    Contact(std::string first_name, std::string last_name, PhoneNumber phone_number){
      first_name_ = first_name;
      last_name_ = last_name;
      phone_numbers_.push_back(phone_number);
      full_name_ = first_name_ + last_name_;
    }

    Contact(std::string first_name, std::string last_name, std::vector<PhoneNumber> phone_number){
      first_name_ = first_name;
      last_name_ = last_name;
      phone_numbers_ = phone_number;
      full_name_ = first_name_ + last_name_;
    }

    bool addNumber(PhoneNumber phone_number){
      for(PhoneNumber x: phone_numbers_){
        if(x.getNumber() == phone_number.getNumber()){
          return false;
        }
      }
      phone_numbers_.push_back(phone_number);
      return true;
    }

    std::string getFirstName(){
      return first_name_;
    }

    std::string getLastName(){
      return last_name_;
    }

    std::vector<PhoneNumber> getPhoneNumbers(){
      return phone_numbers_;
    }

    std::string getFullName(){
      return full_name_;
    }

    friend std::ostream &operator<<(std::ostream &out, const Contact &contact);


};

std::ostream &operator<<(std::ostream &out, const Contact &contact){
  out<<contact.first_name_<< " " << contact.last_name_<<std::endl;
  if(contact.phone_numbers_.size()==0){
    out<<"No Numbers for this contact\n\n";
    return out;
  }
  for(PhoneNumber i : contact.phone_numbers_){
    out<<'\t'<<i<<std::endl;
  }
  out<<'\n';
  return out;
}

#endif
