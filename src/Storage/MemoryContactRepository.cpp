#include "MemoryContactRepository.h"
#include <vector>

std::vector<CContact> CMemoryContactRepository::m_vecData;

CMemoryContactRepository::CMemoryContactRepository() {}

std::vector<CContact> CMemoryContactRepository::GetAll() { return m_vecData; }

const CContact &CMemoryContactRepository::GetById(int nId) {
  return m_vecData.at(nId - 1);
}

void CMemoryContactRepository::Create(const CContact &newItem) {
  m_vecData.push_back(CContact(newItem.GetFirstName(), newItem.GetLastName(),
                               newItem.GetAge(), newItem.GetPhoneNr()));
}

void CMemoryContactRepository::Delete(int nID) {
  m_vecData.erase(m_vecData.begin() + (nID - 1));
}
void CMemoryContactRepository::Update(int nID, const CContact &updatedItem) {
  CContact &item = m_vecData.at((nID - 1));
  item.SetFirstName(updatedItem.GetFirstName());
  item.SetLastName(updatedItem.GetLastName());
  item.SetAge(updatedItem.GetAge());
  item.SetPhoneNr(updatedItem.GetPhoneNr());
}
