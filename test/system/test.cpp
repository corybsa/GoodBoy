#include "includes/test.h"
#include <iostream>
#include <sstream>

Test::Test() {
    failed = 0;
}

void Test::addTest(std::function<void()> func) {
    tests.push_back(func);
}

void Test::run() {
    std::vector<std::function<void()>>::iterator it = tests.begin();

    for(std::function<void()> t : tests) {
        beforeEach();
        t();
    }

    if(failed == 0) {
        std::cout << "\033[0;32mAll tests passed!\033[0m\n";
    } else {
        std::cout << +failed << " tests failed!\n";
    }
}

void Test::expect(byte value, byte expected, char* message) {
    if(value != expected) {
        std::stringstream ss;
        ss << std::hex << std::uppercase << "\033[0;31m" << message << "\033[0m" << " Expected $" << +value << " to be $" << +expected << "\n";
        std::cout << ss.str();
        failed++;
    }
}

void Test::expect(word value, word expected, char* message) {
    if(value != expected) {
        std::stringstream ss;
        ss << std::hex << std::uppercase << "\033[0;31m" << message << "\033[0m" << " Expected $" << +value << " to be $" << +expected << "\n";
        std::cout << ss.str();
        failed++;
    }
}

void Test::expect(bool value, bool expected, char* message) {
    if(value != expected) {
        std::stringstream ss;
        ss << "\033[0;31m" << message << "\033[0m" << " Expected " << value << " to be " << expected << "\n";
        std::cout << ss.str();
        failed++;
    }
}
