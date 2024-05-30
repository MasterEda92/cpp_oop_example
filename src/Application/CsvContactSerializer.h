#pragma once
#include "../Core/Interfaces/IContactSerializer.h"

class CCsvContactSerializer : public IContactSerializer<std::string> {
public:
  virtual std::string Serialize(const CContact &item) override;
};
