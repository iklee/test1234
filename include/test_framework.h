#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <iostream>
#include <string>
#include <vector>

class TestRunner {
public:
    struct TestResult {
        std::string test_name;
        bool passed;
        std::string message;
    };

    static TestRunner& instance() {
        static TestRunner runner;
        return runner;
    }

    void add_test(const std::string& name, bool passed, const std::string& message = "") {
        TestResult result = {name, passed, message};
        results.push_back(result);
    }

    void run_summary() {
        int passed = 0;
        int failed = 0;

        std::cout << "\n========== TEST RESULTS ==========\n" << std::endl;
        
        for (const auto& result : results) {
            if (result.passed) {
                std::cout << "[PASS] " << result.test_name << std::endl;
                passed++;
            } else {
                std::cout << "[FAIL] " << result.test_name << std::endl;
                if (!result.message.empty()) {
                    std::cout << "       " << result.message << std::endl;
                }
                failed++;
            }
        }

        std::cout << "\n==================================\n" << std::endl;
        std::cout << "Total: " << results.size() << " tests" << std::endl;
        std::cout << "Passed: " << passed << std::endl;
        std::cout << "Failed: " << failed << std::endl;
        std::cout << "==================================\n" << std::endl;
    }

    bool all_passed() const {
        for (const auto& result : results) {
            if (!result.passed) {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<TestResult> results;
};

#define ASSERT_EQUAL(a, b) \
    do { \
        if ((a) == (b)) { \
            TestRunner::instance().add_test(std::string(__func__) + " - " + #a " == " + #b, true); \
        } else { \
            TestRunner::instance().add_test(std::string(__func__) + " - " + #a " == " + #b, false, \
                                           "Expected " + std::string(#b) + ", got different value"); \
        } \
    } while(0)

#define ASSERT_TRUE(condition) \
    do { \
        if (condition) { \
            TestRunner::instance().add_test(std::string(__func__) + " - " + #condition, true); \
        } else { \
            TestRunner::instance().add_test(std::string(__func__) + " - " + #condition, false, \
                                           "Condition was false"); \
        } \
    } while(0)

#define ASSERT_FALSE(condition) \
    do { \
        if (!(condition)) { \
            TestRunner::instance().add_test(std::string(__func__) + " - !" + #condition, true); \
        } else { \
            TestRunner::instance().add_test(std::string(__func__) + " - !" + #condition, false, \
                                           "Condition was true"); \
        } \
    } while(0)

#endif // TEST_FRAMEWORK_H
