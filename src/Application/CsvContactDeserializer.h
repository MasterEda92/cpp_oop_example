#pragma once
#include "../Core/Interfaces/IContactDeserializer.h"

class CCsvContactDeserializer : public IContactDeserializer<std::string> {
public:
  virtual CContact Deserialize(const std::string &data) override;
};
