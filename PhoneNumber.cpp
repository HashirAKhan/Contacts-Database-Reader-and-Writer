#include "PhoneNumber.hpp"

PhoneNumber::PhoneNumber(){
  number_ = -1;
  type_ = "";
}

PhoneNumber::PhoneNumber(std::string number, std::string type){
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
  else if(typetest == "MOBIL"){
    type_ = "Mobil";
  }
  else{
    type_ = "";
  }
}

PhoneNumber::PhoneNumber(long number, std::string type){
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

std::ostream &operator<<(std::ostream &out, const Contact &phone_number){
  if(contact.number_ == -1){
    return out;
  }
  std::string num = std::to_string(phone_number.number_);
  for(int i = num.length()-4; i > 0; i -= 3){
    std::string left = num.substr(0,i);
    std::string right = num.substr(i, num.length());
    num = left + "-" + right;
  }
  out << num << " " << phone_number.type_;
  return out;
}
