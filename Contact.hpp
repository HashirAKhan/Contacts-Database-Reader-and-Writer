#ifndef CONTACT_
#define CONTACT_

#include <iostream>

class Contact{
  private:
    int number_;
    std::string type_;

  public:

    Contact();

    Contact(int number, std::string type);

    friend std::ostream &operator<<(std::ostream &out, const Contact &contact);

};

#endif
