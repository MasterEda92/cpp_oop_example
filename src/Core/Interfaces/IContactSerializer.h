#pragma once
#include "../Contact.h"
#include "ISerializer.h"

template <typename T>
class IContactSerializer : public ISerializer<CContact, T> {
public:
  virtual T Serialize(const CContact &item) = 0;
};
