#pragma once

#include <iostream>
#include <memory>


#if defined(_WIN32)
#ifdef LUCKY_LOGGER_EXPORTS
#define LUCKY_LOGGER_API __declspec(dllexport)
#else
#define LUCKY_LOGGER_API __declspec(dllimport)
#endif
#else // #if !defined(_WIN32)
#define LUCKY_LOGGER_API
#endif

#if !defined(LUCKY_LOGGER_LEVEL)
#define LUCKY_LOGGER_LEVEL 1
#endif


namespace lky {
namespace details {
  enum LogLevel {
    Trace=1,
    Info=2,
    Debug=3,
    Warn=4,
    Error=5,
    Critical=6,
    None=7
  };
}

  constexpr int LoggingLevel = LUCKY_LOGGER_LEVEL;

  template<typename T>
  void Log(const details::LogLevel &level, const T &msg) {
    std::cout << msg << '\n';
  }

  template<typename T>
  void Trace(const T &msg) {
    if constexpr (LoggingLevel <= details::LogLevel::Trace) {
        Log(details::LogLevel::Trace, msg);
    }
  }

  template<typename T>
  void Info(const T &msg) {
    if constexpr (LoggingLevel <= details::LogLevel::Info) {
        Log(details::LogLevel::Info, msg);
    }
  }

  template<typename T>
  void Debug(const T &msg) {
    if constexpr (LoggingLevel <= details::LogLevel::Debug) {
        Log(details::LogLevel::Debug, msg);
    }
  }

  template<typename T>
  void Warn(const T &msg) {
    if constexpr (LoggingLevel <= details::LogLevel::Warn) {
        Log(details::LogLevel::Warn, msg);
    }
  }

  template<typename T>
  void Error(const T &msg) {
    if constexpr (LoggingLevel <= details::LogLevel::Error) {
        Log(details::LogLevel::Error, msg);
    }
  }

  template<typename T>
  void Critical(const T &msg) {
    if constexpr (LoggingLevel <= details::LogLevel::Critical) {
        Log(details::LogLevel::Critical, msg);
    }
  }
}
