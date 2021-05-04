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

void Test::run(std::string *results) {
    beforeAll();

    auto it = tests.begin();

    for(const auto &t : tests) {
        beforeEach();
        t();
    }

    tearDown();

    if(testsFailed == 0) {
        testResults << std::endl << std::dec << testsPassed << "/" << testsTotal << " tests passed!" << std::endl;
    } else {
        testResults << std::endl << std::dec << testsFailed << "/" << testsTotal << " tests failed!" << std::endl;
    }

    *results += testResults.str();
}

void Test::expect(unsigned long long value, unsigned long long expected, const char* message) {
    if(value != expected) {
        testResults << std::endl << message << std::endl;
        testResults << std::hex << std::uppercase << "Expected $" << +value << " to be $" << +expected;
        // testResults << std::dec << " in " << yellow << loc.file_name() << white << ", function " << magenta << loc.function_name();
        // testResults << white << " on " << magenta << "line " << loc.line() << white << std::endl;
        // std::cout << std::endl << testResults.str();
        testsFailed++;
    } else {
        testsPassed++;
    }

    testsTotal++;
}
