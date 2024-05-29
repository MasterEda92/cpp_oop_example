#pragma once
#include "../Core/Interfaces/IContactRepository.h"
#include "../Core/Interfaces/IContactService.h"
#include <memory>

class CContactService : public IContactService {
public:
  CContactService(std::shared_ptr<IContactRepository> pRepository)
      : m_pRepository(pRepository){};

  virtual std::vector<CContact> GetContacts() override;

private:
  std::shared_ptr<IContactRepository> m_pRepository;
};
