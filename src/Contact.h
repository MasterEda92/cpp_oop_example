#pragma once
#include <string>

class CContact {
public:
  CContact(std::string strFirstName, std::string strLastName, int nAge,
           std::string strPhoneNr)
      : m_strFirstName(strFirstName), m_strLastName(strLastName), m_nAge(nAge),
        m_strPhoneNr(strPhoneNr) {}

  CContact(std::string strCsv);

  std::string GetFirstName() { return m_strFirstName; }
  void SetFirstName(std::string strFirstName) { m_strFirstName = strFirstName; }

  std::string GetLastName() { return m_strLastName; }
  void SetLastName(std::string strLastName) { m_strLastName = strLastName; }

  int GetAge() { return m_nAge; }
  void SetAge(int nAge) { m_nAge = nAge; }

  std::string GetPhoneNr() const { return m_strPhoneNr; }
  void SetPhoneNr(std::string strPhoneNr) { m_strPhoneNr = strPhoneNr; }

  std::string ToCsv();

private:
  std::string m_strFirstName;
  std::string m_strLastName;
  int m_nAge;
  std::string m_strPhoneNr;
};
