#include "includes/test.h"
#include <iostream>

Test::Test() {
    testsFailed = 0;
    testsPassed = 0;
    testsTotal = 0;
    white = "\033[0m";
    red = "\033[1;31m";
    green = "\033[1;32m";
    yellow = "\033[1;33m";
    magenta = "\033[1;35m";
    cyan = "\033[1;36m";
}

void Test::addTest(const std::function<void()>& func) {
    tests.push_back(func);
}

void Test::run() {
    beforeAll();

    auto it = tests.begin();

    for(const auto &t : tests) {
        beforeEach();
        t();
    }

    tearDown();

    if(testsFailed == 0) {
        std::cout << std::endl << green << +testsPassed << "/" << +testsTotal << " tests passed!" << white << std::endl;
    } else {
        std::cout << std::endl << red << +testsFailed << "/" << +testsTotal << " tests failed!" << white << std::endl;
    }
}

void Test::expect(size_t value, size_t expected, char* message, std::experimental::source_location loc) {
    if(value != expected) {
        std::stringstream ss;
        ss << red << message << white << std::endl;
        ss << std::hex << std::uppercase << cyan << "Expected $" << +value << " to be $" << +expected << white;
        ss << std::dec << " in " << yellow << loc.file_name() << white << ", function " << magenta << loc.function_name();
        ss << white << " on " << magenta << "line " << loc.line() << white << std::endl;
        std::cout << std::endl << ss.str();
        testsFailed++;
    } else {
        testsPassed++;
    }

    testsTotal++;
}
