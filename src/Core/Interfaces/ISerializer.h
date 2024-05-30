#pragma once

template <typename T, typename U> class ISerializer {
public:
  virtual U Serialize(const T &item) = 0;
};
