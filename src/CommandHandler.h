#pragma once
#include "Contact.h"
#include <memory>
#include <vector>

class CCommandHandler {
public:
  CCommandHandler();

  void ListCommands();
  bool Handle();

private:
  void List();
  void Create();
  void Edit();
  void Delete();
  void Help();
  void Save();
  void Load();

  std::string FirstNameFromInput();
  std::string LastNameFromInput();
  int AgeFromInput();

  int GetContactIndex();
  int GetFieldIndex();
  std::string GetNewFieldValue();

private:
  std::vector<std::shared_ptr<CContact>> m_vecContacts;
};
