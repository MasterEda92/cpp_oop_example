#include "Contact.h"
#include <sstream>

CContact::CContact(std::string strCsv) {
  std::istringstream ss(strCsv);
  std::string token;

  std::string strFirstName, strLastName, nAge, strPhoneNr;
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
    case 3:
      strPhoneNr = token;
      break;
    default:
      break;
    }
    ++nCounter;
  }
  m_strFirstName = strFirstName;
  m_strLastName = strLastName;
  m_nAge = std::stoi(nAge);
  m_strPhoneNr = strPhoneNr;
}

std::string CContact::ToCsv() {
  std::ostringstream oss;
  oss << m_strFirstName << ";" << m_strLastName << ";" << m_nAge << ";"
      << m_strPhoneNr;

  return oss.str();
}
