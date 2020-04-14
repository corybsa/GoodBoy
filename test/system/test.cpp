#include "includes/test.h"
#include <iostream>
#include <sstream>

Test::Test() {
    failed = 0;
    white = "\033[0m";
    red = "\033[1;31m";
    green = "\033[1;32m";
    yellow = "\033[1;33m";
    magenta = "\033[1;35m";
    cyan = "\033[1;36m";
}

void Test::addTest(std::function<void()> func) {
    tests.push_back(func);
}

void Test::run() {
    beforeAll();

    std::vector<std::function<void()>>::iterator it = tests.begin();

    for(std::function<void()> t : tests) {
        beforeEach();
        t();
    }

    tearDown();

    if(failed == 0) {
        std::cout << std::endl << green << "All tests passed!" << white << std::endl;
    } else {
        std::cout << std::endl << +failed << " test" << (failed == 1 ? "" : "s") << " failed!" << std::endl;
    }
}

void Test::expect(size_t value, size_t expected, char* message, std::experimental::source_location loc = std::experimental::source_location::current()) {
    if(value != expected) {
        std::stringstream ss;
        ss << red << message << white << std::endl;
        ss << std::hex << std::uppercase << cyan << "Expected $" << +value << " to be $" << +expected << white;
        ss << std::dec << " in " << yellow << loc.file_name() << white << ", function " << magenta << loc.function_name();
        ss << white << " on " << magenta << "line " << loc.line() << white << std::endl;
        std::cout << std::endl << ss.str();
        failed++;
    }
}
