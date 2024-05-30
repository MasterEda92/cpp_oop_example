#pragma once
#include "CliCommandHandler.h"
#include <cstddef>
#include <functional>

class CCliCommand {
public:
  CCliCommand(std::string strCommand, std::string strDescription,
              std::function<void()> fnCommand)
      : m_strCommand(strCommand), m_strDescription(strDescription),
        m_fnCommand(fnCommand), m_pHandler(nullptr) {}

  std::string GetCommand() const { return m_strCommand; }
  std::string GetDescription() const { return m_strDescription; }
  void SetCommandFn(std::function<void()> fn) { m_fnCommand = fn; }
  void SetCommandHandler(CCliCommandHandler *pHandler) {
    m_pHandler = pHandler;
  }
  void Run() { m_fnCommand(); }

protected:
  std::string m_strCommand;
  std::string m_strDescription;
  std::function<void()> m_fnCommand;

  CCliCommandHandler *m_pHandler;
};
