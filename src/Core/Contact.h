#pragma once
#include <string>

class CContact {
public:
  CContact(std::string strFirstName, std::string strLastName, int nAge)
      : m_strFirstName(strFirstName), m_strLastName(strLastName), m_nAge(nAge) {
  }

  CContact(std::string strCsv);

  std::string GetFirstName() const { return m_strFirstName; }
  void SetFirstName(std::string strFirstName) { m_strFirstName = strFirstName; }

  std::string GetLastName() const { return m_strLastName; }
  void SetLastName(std::string strLastName) { m_strLastName = strLastName; }

  int GetAge() const { return m_nAge; }
  void SetAge(int nAge) { m_nAge = nAge; }

  std::string ToCsv() const;

private:
  std::string m_strFirstName;
  std::string m_strLastName;
  int m_nAge;
};
