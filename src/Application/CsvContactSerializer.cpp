#include "CsvContactSerializer.h"
#include <sstream>

std::string CCsvContactSerializer::Serialize(const CContact &item) {
  std::ostringstream oss;
  oss << item.GetFirstName() << ";" << item.GetLastName() << ";"
      << item.GetAge(); // << ";" << pContact->phone_nr;

  return oss.str();
}
