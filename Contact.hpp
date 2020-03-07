#ifndef CONTACT_
#define CONTACT_

#include <iostream>

class Contact{
  private:
    long number_;
    std::string type_;

  public:

    Contact();

    Contact(std::string number, std::string type);

    Contact(long number, std::string type);

    friend std::ostream &operator<<(std::ostream &out, const Contact &contact);

};

#endif
