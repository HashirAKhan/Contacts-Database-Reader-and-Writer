#include "Contact.hpp"

Contact::Contact(){
  number_ = 000000000;
  type_ = "";
}

Contact::Contact(int number, std::string type){
  number_ = number;
  type_ = type;
}

std::ostream &operator<<(std::ostream &out, const Contact &contact){
  std::string temp = "";
  

  return out;
}
