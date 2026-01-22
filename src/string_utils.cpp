#include "string_utils.h"
#include <algorithm>
#include <cctype>

namespace SimpleString {

std::string to_uppercase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), 
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}

std::string to_lowercase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), 
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}

std::string reverse(const std::string& str) {
    std::string result = str;
    std::reverse(result.begin(), result.end());
    return result;
}

int count_substring(const std::string& str, const std::string& substr) {
    if (substr.empty()) {
        return 0;
    }
    
    int count = 0;
    size_t pos = 0;
    while ((pos = str.find(substr, pos)) != std::string::npos) {
        count++;
        pos += substr.length();
    }
    return count;
}

std::string replace_all(const std::string& str, const std::string& from, const std::string& to) {
    std::string result = str;
    size_t pos = 0;
    
    while ((pos = result.find(from, pos)) != std::string::npos) {
        result.replace(pos, from.length(), to);
        pos += to.length();
    }
    
    return result;
}

} // namespace SimpleString
