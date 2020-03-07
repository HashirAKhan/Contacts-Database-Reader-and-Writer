#include "Contact.hpp"

int main(){
  Contact a = Contact("+1-(111)-111-1111","Home");
  Contact b = Contact(2222222,"Mobil");
  Contact c = Contact("333-333-3333","WORK");
  Contact d = Contact("4444444444","ASNDKLAN");
  std::cout<<a<<std::endl;
  std::cout<<b<<std::endl;
  std::cout<<c<<std::endl;
  std::cout<<d<<std::endl;
  return 0;
}
