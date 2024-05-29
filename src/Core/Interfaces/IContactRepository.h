#pragma once
#include "../Contact.h"
#include "IRepository.h"

class IContactRepository : public IRepository<CContact> {
public:
  virtual std::vector<CContact> GetAll() = 0;
  virtual CContact GetById(int nId) = 0;
  virtual void Create(const CContact &newItem) = 0;
  virtual void Delete(int nID) = 0;
  virtual void Update(int nID, const CContact &updatedItem) = 0;
};
