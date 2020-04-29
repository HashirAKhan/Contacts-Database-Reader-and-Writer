#ifndef CONTACT_APPLICATION_
#define CONTACT_APPLICATION_

#include "DataBase.hpp"
#include <chrono>
#include <thread>

//Main class
class ContactApplication{
  private:
    std::list<Contact> contact_list_;
    DataBase database_;

    void removeAll(){
      while(!contact_list_.empty()){
        contact_list_.pop_back();
      }
      database_.reset();
    }

    bool removeNumber(Contact number){
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

    bool checkNum(std::string input,std::string start, std::string end){
      return (input <= end && input >= start);
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
      std::string input;
      if(result){
        system("clear");
        std::cout<<"A Contact For This Name Already Exists\n\n";
        std::cout<<"\t1. Add Number For This Contact\n";
        std::cout<<"\t2. Enter New Contact Name\n";
        std::cout<<"\t3. Return To Main Menu\n\n";
        do{
          std::cout<<"Please select an option(1-3): ";

          std::cin>>input;
        } while(!checkNum(input,"1", "3"));
        if(input == "1"){
          return 2;
        }
        else if(input == "2"){
          return 1;
        }
        else{
          return 3;
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

    void addPhoneNumberMenu(std::string first_name, std::string last_name){
      std::string number;
      std::string type;
      system("clear");
      do{
        std::cout<<"Please Enter The Phone Number You Are Adding To This Contact: ";
        std::cin>>number;
      } while(!validNumber(number));

      std::string input;
      system("clear");
      std::cout<<"What Type Of Phone Number Is This\n";
      std::cout<<"\t1. Home\n";
      std::cout<<"\t2. Mobil\n";
      std::cout<<"\t3. Work\n\n";
      do{
        std::cout<<"\tPlease select an option(1-3): ";
        std::cin>>input;
      }while(!checkNum(input, "1", "3"));

      if(input == "1"){
        type = "Home";
      }
      else if(input == "2"){
        type = "Mobil";
      }
      else if(input == "3"){
        type = "Work";
      }

      Contact temp = Contact(first_name, last_name, PhoneNumber(number, type));
      system("clear");
      if(addContact(temp)){
        database_.addNumber(temp);
        std::cout<<"Contact Was Added Successfully! Returning To Main Menu\n";
        return;
      }
      else{
        std::cout<<"Number Already Exist For This Contact\nReturning To Main Menu\n";
        return;
      }
    }

    void addContactMenu(){
      system("clear");
      int temp = 0;
      std::string first_name;
      std::string last_name;
      do{
        std::cout<<"Please enter First name of new contact: ";
        std::cin>>first_name;
        std::cout<<"Please enter Last name of new contact: ";
        std::cin>>last_name;
        std::string fullname = first_name + " " + last_name;
        temp = checkIfNameExist(fullname);
      }while(temp <2);
      if(temp == 3){
        return;
      }
      addPhoneNumberMenu(first_name, last_name);
    }

    void selectContactToAdd(){
      system("clear");
      int num = 0;
      std::list<Contact>::iterator it;
      for(it = contact_list_.begin(); it != contact_list_.end(); it++){
        num++;
        std::cout<<"\t"<<num<<". "<<it->getFullName()<<"\n";
      }
      std::cout<<"\n";
      std::string input;
      do{
        std::cout<<"Enter 0 To Return To Main Menu\n";
        std::cout<<"Please select a Contact(1-"<<num<<"): ";
        std::cin>>input;
      }while(!checkNum(input, "0", std::to_string(num)));

      if(input == "0"){
        return;
      }
      num = stoi(input);

      it = contact_list_.begin();
      std::advance(it, num-1);
      addPhoneNumberMenu(it->getFirstName(), it->getLastName());
    }

    void newContactOrNumberMenu(){
      system("clear");
      std::string input;
      std::cout<<"1. Add New Contact\n";
      std::cout<<"2. Add Number To Existing Contact\n";
      std::cout<<"3. Return To Main Menu\n\n";
      do{
        std::cout<<"Enter 0 To Main Menu\n";
        std::cout<<"Please select an option(1-3): ";
        std::cin>>input;
      } while(!checkNum(input, "0", "3"));
      if(input == "1"){
        addContactMenu();
      }
      else if(input == "2"){
        selectContactToAdd();
      }
      else if(input == "3"){
        return;
      }
    }

    bool checkOption(std::string input){
      for(int i = 0; i < input.length(); i++){
        input[i]=toupper(input[i]);
      }
      return (input == "Y"||input == "N");
    }

    void selectContactToDelete(){
      system("clear");
      int num = 0;
      std::list<Contact>::iterator it;
      for(it = contact_list_.begin(); it != contact_list_.end(); it++){
        num++;
        std::cout<<"\t"<<num<<". "<<it->getFullName()<<"\n";
      }
      std::cout<<"\n";
      std::string input;
      do{
        std::cout<<"Enter 0 To Return To Main Menu\n";
        std::cout<<"Please select a Contact(1-"<<num<<"): ";
        std::cin>>input;
      }while(!checkNum(input, "0", std::to_string(num)));

      if(input == "0"){
        return;
      }

      system("clear");
      it = contact_list_.begin();
      std::advance(it, num-1);
      std::cout<<*it;
      std::cout<<"Are You Sure You Want To Delete The Contact Above?\n";
      do{
        std::cout<<"Enter \'Y\' OR \'N\': ";
        std::cin>>input;
      }while(!checkOption(input));

      if(input == "Y"){
        system("clear");
        if(removeContact(it->getFullName())){
          std::cout<<"Contact Deleted Successfully! Returning To Main Menu\n";
        }
        else{
          std::cout<<"Error Deleting Contact! Returning To Main Menu\n";
        }
      }
      else{
        std::cout<<"Returning To Main Menu\n";
      }
    }

    void selectContactNumberToDelete(){
      system("clear");
      int num = 0;
      std::list<Contact>::iterator it;
      for(it = contact_list_.begin(); it != contact_list_.end(); it++){
        num++;
        std::cout<<"\t"<<num<<". "<<it->getFullName()<<"\n";
      }
      std::cout<<"\n";
      std::string input;
      do{
        std::cout<<"Enter 0 To Return To Main Menu\n";
        std::cout<<"Please select a Contact(1-"<<num<<"): ";
        std::cin>>input;
      }while(!checkNum(input, "0", std::to_string(num)));

      if(input == "0"){
        return;
      }
      system("clear");
      it = contact_list_.begin();

      num = stoi(input);
      std::advance(it, num-1);
      std::cout<<it->getFullName()<<"\n";
      num = 0;
      for(int i = 0; i < it->getPhoneNumbers().size(); i++){
        num++;
        std::cout<<"\t"<<num<<". "<<it->getPhoneNumbers()[i].getNumber()<<"\n";
      }
      do{
        std::cout<<"Enter 0 To Return To Main Menu\n";
        std::cout<<"Please select a Number(1-"<<num<<"): ";
        std::cin>>input;
      } while(!checkNum(input, "0", std::to_string(num)));

      if(input == "0"){
        return;
      }
      system("clear");

      num = stoi(input);
      std::cout<<it->getPhoneNumbers()[num-1]<<"\n";
      std::cout<<"Are You Sure You Want To Delete The Number Above?\n";
      do{
        std::cout<<"Enter \'Y\' OR \'N\': ";
        std::cin>>input;
      } while(!checkOption(input));

      if(input == "Y"){
        system("clear");
        if(removeNumber(Contact(it->getFirstName(), it->getLastName(), it->getPhoneNumbers()[num-1]))){
          std::cout<<"Number Deleted Successfully!";

        }
        else {
          std::cout<<"Error Deleting Number!";
        }
      }
      else {
        std::cout<<"Press Enter To Return To Main Menu";
      }
    }

    void deleteAllMenu(){
      system("Clear");
      std::cout<<"WARNING ARE YOU SURE YOU WANT TO DELETE ALL CONTACTS?\n";
      std::string input;
      do{
        std::cout<<"Enter \'Y\' OR \'N\': ";
        std::cin>>input;
      }while(!checkOption(input));

      system("clear");
      if(input == "Y"){
          std::cout<<"All Contacts Deleted Successfully! Press Enter To Return To Main Menu";
          removeAll();
        }
      else{
        std::cout<<"Press Enter To Return To Main Menu";
      }
    }



    void deleteContactOrNumber(){
      system("clear");
      std::string input;
      std::cout<<"1. Delete Contact\n";
      std::cout<<"2. Delete A Number From Contact\n";
      std::cout<<"3. Delete All Contacts\n";
      std::cout<<"4. Return To Main Menu\n\n";
      do{
        std::cout<<"Please select an option(1-4): ";
        std::cin>>input;
      } while(!checkNum(input, "1", "4"));
      if(input == "1"){
        selectContactToDelete();
      }
      else if(input == "2"){
        selectContactNumberToDelete();
      }
      else if(input == "3"){
        deleteAllMenu();
      }
      else{
        return;
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
        } while (!checkNum(input, "1", "4"));
        if(input=="1"){
          system("clear");
          std::cout<<*this;

          std::cout<<"\n\t1. Return To Main Menu\n";
          std::cout<<"\t2. Exit Application\n\n";
          do{
            std::cout<<"\tPlease select an option(1-2): ";
            std::cin>>input;
          }while(!checkNum(input, "1", "2"));
          if(input == "1"){
          }
          else if(input == "2"){
            run = false;
          }
        }
        else if (input == "2"){
          newContactOrNumberMenu();
        }
        else if (input == "3"){
          deleteContactOrNumber();
        }
        else if(input == "4"){
          run = false;
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
