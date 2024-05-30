#pragma once
#include "../Core/Interfaces/IContactRepository.h"
#include <vector>

class CMemoryContactRepository : public IContactRepository {
public:
  CMemoryContactRepository();

  virtual std::vector<CContact> GetAll() override;
  virtual const CContact &GetById(int nId) override;
  virtual void Create(const CContact &newItem) override;
  virtual void Delete(int nID) override;
  virtual void Update(int nID, const CContact &updatedItem) override;

private:
  static std::vector<CContact> m_vecData;
};
