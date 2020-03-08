#ifndef CONTACT_
#define CONTACT_

#include "PhoneNumber.hpp"
#include <vector>

class Contact{
  private:
    std::string first_name_;
    std::string last_name_;
    std::vector<int> phone_numbers_;

  public:
    Contact();

    Contact(std::string first_name, std::string last_name, PhoneNumber phone_number);

};

#endif
