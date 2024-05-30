#pragma once
#include "../Contact.h"
#include <vector>

class IContactService {
public:
  virtual std::vector<CContact> GetContacts() = 0;
  virtual const CContact &GetContact(int nId) = 0;
  virtual void CreateContact(const CContact &newContact) = 0;
  virtual void DeleteContact(int nId) = 0;
  virtual void UpdateContact(int nId, const CContact &updatedContact) = 0;
};
