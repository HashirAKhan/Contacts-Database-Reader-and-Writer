#ifndef CONTACT_APPLICATION_
#define CONTACT_APPLICATION_

#include "DataBase.hpp"

//Main class
class ContactApplication{
  private:
    std::list<Contact> contact_list_;
    DataBase database_;

    bool removeNumber(PhoneNumber number){
      for(std::list<Contact>::iterator i = contact_list_.begin(); i != contact_list_.end(); i++){
        if(i->removeNumber(number)){
          database_.removeNumber(number);
          return true;
        }
      }
      return true;

    }

    bool removeContact(std::string name){
      for(std::list<Contact>::iterator i = contact_list_.begin(); i != contact_list_.end(); i++){
        if(i->getFullName() == name){
          database_.removeContact(name);
          contact_list_.erase(i);
          return true;
        }
      }
      return true;
    }


    bool addContact(Contact contact){
      std::list<Contact>::iterator it;
      for(it = contact_list_.begin(); it != contact_list_.end(); it++){
        if(it->getFullName() == contact.getFullName()){
          return it->addNumber(contact.getPhoneNumbers()[0]);
        }
        if(it->getFullName()>contact.getFullName()){
          break;
        }
      }
      contact_list_.insert(it, contact);
      return true;
    }

    bool addNumber (Contact contact){
      if(addContact(contact)){
        database_.addNumber(contact);
        return true;
      }
      return false;
    }

    bool checkNum(std::string input, std::string options){
      return (input < options && input > "0");
    }

    bool findName(std::string name){
      std::list<Contact>::iterator it;
      for(it = contact_list_.begin(); it != contact_list_.end(); it++){
        if (name == it->getFullName()){
          return true;
        }
      }
      return false;
    }

    int checkIfNameExist(std::string name){
      bool result = findName(name);
      if(result){
        system("clear");
        std::cout<<"A Contact For This Name Already Exists\n\n";
        std::cout<<"\t1. Add Number For This Contact\n";
        std::cout<<"\t2. Enter New Contact Name\n";
        std::cout<<"\t3. Return To Main Menu\n\n"
        do{
          std::cout<<"Please select an option(1-3): ";
          std::string input;
          std::cin<<input;
        } while(!checkNum(input, "3"))
        if(input == "1"){
          return 2;
        }
        else if(input == "2"){
          return 1
        }
        else{
          return 3
        }
      }
      else{
        return 2;
      }
    }

    bool validNumber(std::string number){
      for(int i = 0; i < number.length(); i++){
        if(!isdigit(number[i])){
          system("clear");
          std::cout<<"Only Enter Numbers!";
          return false;
        }
      }
      return true;
    }

    addPhoneNumberMenu(std::string first_name, std::string last_name){
      std::string number;
      system("clear");
      do{
        std::cout<<"Please Enter The Phone Number You Are Adding To This Contact ";
        std::cin<<number;
      } while(!validNumber(number))

      std::string input;
      std::cout<<"What Type Of Phone Number Is This\n";
      std::cout<<"\t1. Home\n";
      std::cout<<"\t2. Mobil\n";
      std::cout<<"\t3. Word\n\n";
      do{
        std::cout<<"\tPlease select an option(1-3): ";
        CONTINUE WORKING HERE
      }

      Contact(first_name, last_name, number);
    }

    void addContactMenu(){
      system("clear");
      int temp = 0;
      do{
        std::cout<<"Please enter First name of new contact: ";
        std::string first_name;
        std::cin<<first_name;
        std::cout<<"Please enter Last name of new contact: ";
        std::string last_name;
        std::cin<<last_name;
        std::string fullname = first_name + " " + last_name;
        temp = checkIfNameExist(fullname);
      }while(temp <2);
      if(temp == 3){
        return;
      }

      addPhoneNumberMenu(first_name, last_name);


    }

    newContactorNumberMenu(){
      system("clear");
      std::string input;
      std::cout<<"1. Add New Contact\n";
      std::cout<<"2. Add Number To Existing Contact";
      std::cout<<"3. Return To Main Menu";
      do{
        std::cout<<"Please select an option(1-3): ";
        cin>>input;
      } while(!checkNum(input, "3"));
      if(input == "1"){
        addContactMenu();
      }
    }

    void mainMenu(){
      bool run = true;

      while(run){
        system("clear");
        std::cout<<"Contact Application\n";
        std::cout<<"\t1. Show Contact List\n";
        std::cout<<"\t2. Add Contact or Number\n";
        std::cout<<"\t3. Delete Contact or Number\n";
        std::cout<<"\t4. Exit Application\n\n";
        std::string input;
        std::string temp;
        do{
          std::cout<<"\tPlease select an option(1-4): ";
          std::cin>>input;
        } while (!checkNum(input,"4"));
        if(input=="1"){
          std::cout<<*this;
          std::cout<<"Press Enter To Return";
          std::cin>>temp;
        }
        else if (input == "2"){
          newContactorNumberMenu();
        }
      }
    }

  public:
    ContactApplication(){
      database_ = DataBase();
      database_.FileToList(contact_list_);
    }

    void run(){
      mainMenu();
    }


    friend std::ostream &operator<<(std::ostream &out, const ContactApplication &contact_application);


};
std::ostream &operator<<(std::ostream &out, const ContactApplication &contact_application){
  for(Contact i : contact_application.contact_list_){
    out<<i;
  }
  return out;
}

#endif
