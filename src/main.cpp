#include <iostream>
#include "string_utils.h"

using namespace SimpleString;

int main() {
    std::cout << "========== SimpleString Utility ==========\n" << std::endl;

    std::string text = "Hello World";
    
    std::cout << "Original: " << text << std::endl;
    std::cout << "Uppercase: " << to_uppercase(text) << std::endl;
    std::cout << "Lowercase: " << to_lowercase(text) << std::endl;
    std::cout << "Reversed: " << reverse(text) << std::endl;
    
    std::string text_with_spaces = "  Hello World  ";
    std::cout << "Trimmed: '" << trim(text_with_spaces) << "'" << std::endl;
    
    std::string sentence = "The quick brown fox jumps over the lazy dog";
    std::cout << "Count 'o': " << count_substring(sentence, "o") << std::endl;
    std::cout << "Replace 'o' with '0': " << replace_all(sentence, "o", "0") << std::endl;
    
    std::cout << "\n==========================================\n" << std::endl;
    
    return 0;
}
