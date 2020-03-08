#include "Contact.hpp"

Contact::Contact(){
  first_name_ = "";
  last_name_ = "";
}

Contact::Contact(std::string first_name, std::string last_name, PhoneNumber phone_number){
  first_name_ = first_name;
  last_name_ = last_name;
  phone_numbers_.push_back(phone_number);
}
