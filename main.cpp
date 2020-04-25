#include "ContactApplication.hpp"



int main(){
  // PhoneNumber x = PhoneNumber(1111111111,"Home");
  // PhoneNumber y = PhoneNumber("1231231231", "Work");
  // Contact a = Contact("Hashir", "Khan", x);
  // a.addNumber(y);
  // Contact b = Contact("Rachel", "Tieu");
  // std::cout<<a;
  // std::cout<<b;
  ContactApplication application = ContactApplication();
  application.print();
  Contact temp = Contact("Rachel", "Tieu", PhoneNumber("1939492939", "Home"));
  //db.addContact(temp);
  application.removeNum("4920483723");
  application.print();

  return 0;
}
