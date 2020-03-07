#ifndef PHONE_NUMBER_
#define PHONE_NUMBER_

#include <iostream>

class PhoneNumber{
  private:
    long number_;
    std::string type_;

  public:

    PhoneNumber();

    PhoneNumber(std::string number, std::string type);

    PhoneNumber(long number, std::string type);

    friend std::ostream &operator<<(std::ostream &out, const Contact &contact);

};

#endif
