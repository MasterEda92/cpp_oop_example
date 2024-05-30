#pragma once

template <typename T, typename U> class IDeserializer {
public:
  virtual T Deserialize(const U &data) = 0;
};
