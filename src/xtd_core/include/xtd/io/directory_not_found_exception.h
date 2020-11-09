#pragma once
#include "../system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace io {
    /// @brief The exception that is thrown when part of a file or directory cannot be found.
    /// @par Library
    /// xtd.core
    /// @par Examples
    /// The following example demonstrates how to throw and catch an directory_not_found_exception.
    /// @include directory_not_found_exception.cpp
    class directory_not_found_exception :public system_exception {
    public:
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      /// @remarks Message is set with the default message associate to the exception.
      directory_not_found_exception(const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(default_message_, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, error, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, help_link, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit directory_not_found_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, error, help_link, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      /// @remarks Message is set with the default message associate to the exception.
      directory_not_found_exception(const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(default_message_, inner_exception, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, error, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, help_link, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, error, help_link, info) {}
      
      /// @cond
      directory_not_found_exception(const directory_not_found_exception&) = default;
      directory_not_found_exception& operator=(const directory_not_found_exception&) = default;
      /// @endcond
      
    private:
      static constexpr const char* default_message_ = "Attempted to access a path that is not on the disk.";
    };
  }
}

/// @brief Helper on directory_not_found_exception to call it with caller information
/// @remarks Is equivalent to directory_not_found_exception({any argument}, caller_info_)
/// @code
/// void my_func() {
///   if (invalid_info) throw directory_not_found_exception_(); // same as : throw directory_not_found_exception(caller_info_)
///   if (invalid_value) throw directory_not_found_exception_("Bad value"); // same as : throw directory_not_found_exception("Bad value", caller_info_)
///   ...
/// }
/// @endcode
/// @ingroup keywords
#define directory_not_found_exception_(...) directory_not_found_exception(add_caller_info_(__VA_ARGS__))
