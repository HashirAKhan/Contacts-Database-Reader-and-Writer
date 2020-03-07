#include "Contact.hpp"

Contact::Contact(){
  number_ = -1;
  type_ = "";
}

Contact::Contact(std::string number, std::string type){
  if(number == ""){
    number_ = -1;
  }
  std::string num = "";
  for(char digit: number){
    if(isdigit(digit)){
      num += digit;
    }
  }
  number_ = std::stol(num);


  std::string typetest = "";
  for(int i = 0; i < type.length(); i++){
    typetest += toupper(type[i]);
  }

  if(typetest == "HOME"){
    type_ = "Home";
  }
  else if(typetest == "WORK"){
    type_ = "Work";
  }
  else{
    type_ = "";
  }
}

Contact::Contact(long number, std::string type){
  number_ = number;

  std::string typetest = "";
  for(int i = 0; i < type.length(); i++){
    typetest += toupper(type[i]);
  }

  if(typetest == "HOME"){
    type_ = "Home";
  }
  else if(typetest == "WORK"){
    type_ = "Work";
  }
  else if(typetest == "MOBIL"){
    type_ = "Mobil";
  }
  else{
    type_ = "";
  }
}

std::ostream &operator<<(std::ostream &out, const Contact &contact){
  if(contact.number_ == -1){
    return out;
  }
  std::string num = std::to_string(contact.number_);
  for(int i = num.length()-4; i > 0; i -= 3){
    std::string left = num.substr(0,i);
    std::string right = num.substr(i, num.length());
    num = left + "-" + right;
  }
  out << num << " " << contact.type_;
  return out;
}
