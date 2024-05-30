cmake_minimum_required(VERSION 3.15)
project(OOP_Example)

set(CMAKE_CXX_STANDARD 20)

add_executable(
  OOP_Example
  src/main.cpp
  src/Core/Contact.h
  src/Core/Interfaces/IRepository.h
  src/Core/Interfaces/IContactRepository.h
  src/Core/Interfaces/IContactService.h
  src/Core/Interfaces/ISerializer.h
  src/Core/Interfaces/IDeserializer.h
  src/Core/Interfaces/IContactSerializer.h
  src/Core/Interfaces/IContactDeserializer.h
  src/Storage/MemoryContactRepository.h
  src/Storage/MemoryContactRepository.cpp
  src/Application/ContactService.h
  src/Application/ContactService.cpp
  src/Application/CsvContactSerializer.h
  src/Application/CsvContactSerializer.cpp
  src/Application/CsvContactDeserializer.h
  src/Application/CsvContactDeserializer.cpp
  src/UI/CliCommand.h
  src/UI/CliCommandHelpers.h
  src/UI/CliCommandHelpers.cpp
  src/UI/CliCommands/CliListContactsCommand.h
  src/UI/CliCommands/CliListContactsCommand.cpp
  src/UI/CliCommands/CliCreateContactCommand.h
  src/UI/CliCommands/CliCreateContactCommand.cpp
  src/UI/CliCommands/CliDeleteContactCommand.h
  src/UI/CliCommands/CliDeleteContactCommand.cpp
  src/UI/CliCommands/CliUpdateContactCommand.h
  src/UI/CliCommands/CliUpdateContactCommand.cpp
  src/UI/CliCommands/CliImportContactsCommand.h
  src/UI/CliCommands/CliImportContactsCommand.cpp
  src/UI/CliCommands/CliExportContactsCommand.h
  src/UI/CliCommands/CliExportContactsCommand.cpp
  src/UI/CliCommandHandler.h
  src/UI/CliCommandHandler.cpp)
