#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

namespace SimpleString {

// Convert string to uppercase
std::string to_uppercase(const std::string& str);

// Convert string to lowercase
std::string to_lowercase(const std::string& str);

// Trim whitespace from both ends
std::string trim(const std::string& str);

// Reverse a string
std::string reverse(const std::string& str);

// Count occurrences of a substring
int count_substring(const std::string& str, const std::string& substr);

// Replace all occurrences of a substring
std::string replace_all(const std::string& str, const std::string& from, const std::string& to);

} // namespace SimpleString

#endif // STRING_UTILS_H
