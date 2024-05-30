#pragma once
#include "../Core/Interfaces/IContactRepository.h"
#include "../Core/Interfaces/IContactService.h"
#include <memory>

class CContactService : public IContactService {
public:
  CContactService(std::shared_ptr<IContactRepository> pRepository)
      : m_pRepository(pRepository){};

  virtual std::vector<CContact> GetContacts() override;
  virtual const CContact &GetContact(int nId) override;
  virtual void CreateContact(const CContact &newContact) override;
  virtual void DeleteContact(int nId) override;
  virtual void UpdateContact(int nId, const CContact &updatedContact) override;

private:
  std::shared_ptr<IContactRepository> m_pRepository;
};
