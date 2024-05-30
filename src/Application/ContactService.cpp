#include "ContactService.h"

std::vector<CContact> CContactService::GetContacts() {
  return m_pRepository->GetAll();
}

const CContact &CContactService::GetContact(int nId) {
  return m_pRepository->GetById(nId);
}

void CContactService::CreateContact(const CContact &newContact) {
  m_pRepository->Create(newContact);
}

void CContactService::DeleteContact(int nId) { m_pRepository->Delete(nId); }

void CContactService::UpdateContact(int nId, const CContact &updatedContact) {
  m_pRepository->Update(nId, updatedContact);
}
