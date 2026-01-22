#include "string_utils.h"
#include "test_framework.h"

using namespace SimpleString;

void test_to_uppercase() {
    ASSERT_EQUAL(to_uppercase("hello"), std::string("HELLO"));
    ASSERT_EQUAL(to_uppercase("Hello World"), std::string("HELLO WORLD"));
    ASSERT_EQUAL(to_uppercase("123"), std::string("123"));
}

void test_to_lowercase() {
    ASSERT_EQUAL(to_lowercase("HELLO"), std::string("hello"));
    ASSERT_EQUAL(to_lowercase("Hello World"), std::string("hello world"));
    ASSERT_EQUAL(to_lowercase("123"), std::string("123"));
}

void test_trim() {
    ASSERT_EQUAL(trim("  hello  "), std::string("hello"));
    ASSERT_EQUAL(trim("hello"), std::string("hello"));
    ASSERT_EQUAL(trim("   "), std::string(""));
    ASSERT_EQUAL(trim("\t\nhello\n\t"), std::string("hello"));
}

void test_reverse() {
    ASSERT_EQUAL(reverse("hello"), std::string("olleh"));
    ASSERT_EQUAL(reverse("a"), std::string("a"));
    ASSERT_EQUAL(reverse(""), std::string(""));
}

void test_count_substring() {
    ASSERT_EQUAL(count_substring("hello", "l"), 2);
    ASSERT_EQUAL(count_substring("aaaa", "aa"), 2);
    ASSERT_EQUAL(count_substring("hello", "x"), 0);
    ASSERT_EQUAL(count_substring("hello", ""), 0);
}

void test_replace_all() {
    ASSERT_EQUAL(replace_all("hello world", "o", "0"), std::string("hell0 w0rld"));
    ASSERT_EQUAL(replace_all("aaa", "a", "b"), std::string("bbb"));
    ASSERT_EQUAL(replace_all("hello", "x", "y"), std::string("hello"));
}

int main() {
    std::cout << "Running SimpleString Tests...\n" << std::endl;

    test_to_uppercase();
    test_to_lowercase();
    test_trim();
    test_reverse();
    test_count_substring();
    test_replace_all();

    TestRunner::instance().run_summary();

    return TestRunner::instance().all_passed() ? 0 : 1;
}
