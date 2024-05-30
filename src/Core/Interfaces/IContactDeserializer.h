#pragma once
#include "../Contact.h"
#include "IDeserializer.h"

template <typename T>
class IContactDeserializer : public IDeserializer<CContact, T> {
public:
  virtual CContact Deserialize(const T &data) = 0;
};
