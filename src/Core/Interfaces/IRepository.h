#pragma once
#include <vector>

template <typename T> class IRepository {
public:
  virtual std::vector<T> GetAll() = 0;
  virtual const T &GetById(int nId) = 0;
  virtual void Create(const T &newItem) = 0;
  virtual void Delete(int nID) = 0;
  virtual void Update(int nID, const T &updatedItem) = 0;
};
