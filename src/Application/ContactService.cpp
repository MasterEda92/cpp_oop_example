#include "ContactService.h"

std::vector<CContact> CContactService::GetContacts() {
  return m_pRepository->GetAll();
}
