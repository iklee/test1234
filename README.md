# SimpleString

A simple C++ string utility library built with CMake, featuring basic string manipulation functions and automated CI/CD pipeline testing.

## Features

- **String Utilities**:
  - `to_uppercase()` - Convert string to uppercase
  - `to_lowercase()` - Convert string to lowercase
  - `trim()` - Remove whitespace from both ends
  - `reverse()` - Reverse a string
  - `count_substring()` - Count occurrences of a substring
  - `replace_all()` - Replace all occurrences of a substring

- **Built with C++11** - Compatible with modern C++ standards
- **No external dependencies** - Lightweight and standalone
- **Comprehensive testing** - Includes unit tests for all functions
- **GitHub Actions CI/CD** - Automatic build, test, and artifact deployment

## Project Structure

```
simplestring/
├── src/
│   ├── main.cpp                 # Main application
│   └── string_utils.cpp         # String utility implementations
├── include/
│   ├── string_utils.h           # String utility header
│   └── test_framework.h         # Simple test framework
├── tests/
│   └── test_string_utils.cpp    # Unit tests
├── .github/
│   └── workflows/
│       └── build.yml            # GitHub Actions workflow
├── CMakeLists.txt               # CMake build configuration
└── README.md                    # This file
```

## Requirements

- **CMake** >= 3.10
- **C++ compiler** supporting C++11 (g++, clang++, etc.)
- **Linux/Unix environment** (for GitHub Actions pipeline)

### Ubuntu/Debian Installation

```bash
sudo apt-get update
sudo apt-get install -y cmake build-essential
```

### macOS Installation

```bash
brew install cmake
```

## Building

### Create and enter build directory

```bash
mkdir build
cd build
```

### Configure with CMake

```bash
cmake ..
```

### Build the project

```bash
cmake --build . --config Release
```

## Running

### Run the main application

```bash
./simplestring_app
```

Expected output:
```
========== SimpleString Utility ==========

Original: Hello World
Uppercase: HELLO WORLD
Lowercase: hello world
Reversed: dlroW olleH
Trimmed: 'Hello World'
Count 'o': 2
Replace 'o' with '0': The quick brwn f0x jumps 0ver the lazy d0g

==========================================
```

### Run tests

```bash
ctest --verbose
```

Or run the test executable directly:

```bash
./test_runner
```

Expected output:
```
Running SimpleString Tests...

========== TEST RESULTS ==========

[PASS] test_to_uppercase - to_uppercase("hello") == std::string("HELLO")
[PASS] test_to_uppercase - to_uppercase("Hello World") == std::string("HELLO WORLD")
[PASS] test_to_uppercase - to_uppercase("123") == std::string("123")
[PASS] test_to_lowercase - to_lowercase("HELLO") == std::string("hello")
[PASS] test_to_lowercase - to_lowercase("Hello World") == std::string("hello world")
[PASS] test_to_lowercase - to_lowercase("123") == std::string("123")
[PASS] test_trim - trim("  hello  ") == std::string("hello")
[PASS] test_trim - trim("hello") == std::string("hello")
[PASS] test_trim - trim("   ") == std::string("")
[PASS] test_trim - trim("\t\nhello\n\t") == std::string("hello")
[PASS] test_reverse - reverse("hello") == std::string("olleh")
[PASS] test_reverse - reverse("a") == std::string("a")
[PASS] test_reverse - reverse("") == std::string("")
[PASS] test_count_substring - count_substring("hello", "l") == 2
[PASS] test_count_substring - count_substring("aaaa", "aa") == 2
[PASS] test_count_substring - count_substring("hello", "x") == 0
[PASS] test_count_substring - count_substring("hello", "") == 0
[PASS] test_replace_all - replace_all("hello world", "o", "0") == std::string("hell0 w0rld")
[PASS] test_replace_all - replace_all("aaa", "a", "b") == std::string("bbb")
[PASS] test_replace_all - replace_all("hello", "x", "y") == std::string("hello")

==================================

Total: 21 tests
Passed: 21
Failed: 0
==================================
```

## GitHub Actions Pipeline

The project includes an automated CI/CD pipeline (`.github/workflows/build.yml`) that:

1. **Builds** - Compiles the project with CMake on Ubuntu Latest
2. **Tests** - Runs all unit tests via CTest
3. **Deploys** - Uploads artifacts (executables) to GitHub for successful builds

### Pipeline Triggers

- Every push to `main` and `develop` branches
- Every pull request to `main` branch

### Artifacts

Build artifacts (compiled executables) are automatically uploaded to GitHub Actions and retained for 90 days when builds succeed on the main branch.

## Usage Example

```cpp
#include "string_utils.h"
#include <iostream>

using namespace SimpleString;

int main() {
    std::string text = "hello world";
    
    std::cout << "Original: " << text << std::endl;
    std::cout << "Uppercase: " << to_uppercase(text) << std::endl;
    std::cout << "Reversed: " << reverse(text) << std::endl;
    
    return 0;
}
```

## Testing Framework

The project includes a simple, custom test framework (`test_framework.h`) with the following macros:

- `ASSERT_EQUAL(a, b)` - Assert that two values are equal
- `ASSERT_TRUE(condition)` - Assert that a condition is true
- `ASSERT_FALSE(condition)` - Assert that a condition is false

Tests are collected and summarized with pass/fail counts.

## License

MIT License

## Author

Created as a demonstration project for CMake-based C++ development with GitHub Actions CI/CD pipeline.
