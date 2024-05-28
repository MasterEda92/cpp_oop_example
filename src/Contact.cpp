#include "Contact.h"
#include <sstream>

CContact::CContact(std::string strCsv) {
  std::istringstream ss(strCsv);
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
  m_strFirstName = strFirstName;
  m_strLastName = strLastName;
  m_nAge = std::stoi(nAge);
}

std::string CContact::ToCsv() {
  std::ostringstream oss;
  oss << m_strFirstName << ";" << m_strLastName << ";"
      << m_nAge; // << ";" << pContact->phone_nr;

  return oss.str();
}
