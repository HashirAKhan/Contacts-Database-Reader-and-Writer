#include "DataBase.hpp"

int main(){
  // PhoneNumber x = PhoneNumber(1111111111,"Home");
  // PhoneNumber y = PhoneNumber("1231231231", "Work");
  // Contact a = Contact("Hashir", "Khan", x);
  // a.addNumber(y);
  // Contact b = Contact("Rachel", "Tieu");
  // std::cout<<a;
  // std::cout<<b;
  std::map<std::string, Contact> Contact_list;
  DataBase db = DataBase(Contact_list, "database.txt");

  return 0;
}
