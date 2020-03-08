#ifndef DATABASE_
#define DATABASE_


#include "Contact.hpp"
#include <map>


class DataBase{
  DataBase(std::map<std::string, Contact> & contact_list, std::string filename);
};

#endif
