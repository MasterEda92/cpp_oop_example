#pragma once
#include "../Contact.h"
#include <vector>

class IContactService {
public:
  virtual std::vector<CContact> GetContacts() = 0;
};
