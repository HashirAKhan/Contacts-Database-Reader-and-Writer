#include "DataBase.hpp"
#include <fstream>
#include <sstream>

DataBase::DataBase(std::map<std::string, Contact> & contact_list, std::string filename){
  fstream data("filename");

  std::string db_line;
  while(getline(data, db_line)){
    std::string name, contact_info;
  }
}
