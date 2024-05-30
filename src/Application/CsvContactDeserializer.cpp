#include "CsvContactDeserializer.h"
#include <sstream>

CContact CCsvContactDeserializer::Deserialize(const std::string &data) {
  std::istringstream ss(data);
  std::string token;

  std::string strFirstName, strLastName, nAge;
  int nCounter = 0;
  while (std::getline(ss, token, ';')) {
    switch (nCounter) {
    case 0:
      strFirstName = token;
      break;
    case 1:
      strLastName = token;
      break;
    case 2:
      nAge = token;
      break;
    default:
      break;
    }
    ++nCounter;
  }
  return CContact(strFirstName, strLastName, std::stoi(nAge));
}
