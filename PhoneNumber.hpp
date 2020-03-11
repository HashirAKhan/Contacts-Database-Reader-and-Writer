#ifndef PHONE_NUMBER_
#define PHONE_NUMBER_

#include <iostream>

class PhoneNumber{
  private:
    long number_;
    std::string type_;

  public:

    PhoneNumber(){
      number_ = -1;
      type_ = "";
    }

    PhoneNumber(std::string number, std::string type){
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

    PhoneNumber(long number, std::string type){
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

    long getNumber(){
      return number_;
    }

    std::string getType(){
      return type_;
    }

    friend std::ostream &operator<<(std::ostream &out, const PhoneNumber &phone_number);

};

std::ostream &operator<<(std::ostream &out, const PhoneNumber &phone_number){
  if(phone_number.number_ == -1){
    return out;
  }
  std::string num = std::to_string(phone_number.number_);
  for(int i = num.length()-4; i > 0; i -= 3){
    std::string left = num.substr(0,i);
    std::string right = num.substr(i, num.length());
    num = left + "-" + right;
  }
  out<< phone_number.type_ <<": "<< num << " " ;
  return out;
}

#endif
