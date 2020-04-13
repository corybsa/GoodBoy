#ifndef GOODBOY_TEST_H
#define GOODBOY_TEST_H

#include <vector>
#include <functional>
#include <experimental/source_location>
#include "../../../src/system/includes/types.h"
#include <iostream>
#include <sstream>

class Test {
public:
    std::vector<std::function<void()>> tests;
    int failed;

    Test();

    virtual void beforeAll() = 0;
    virtual void beforeEach() = 0;

    void addTest(std::function<void()> func);
    void run();

    template<typename T>
    void expect(T value, T expected, char* message, std::experimental::source_location loc = std::experimental::source_location::current());
};

template<typename T>
void Test::expect(T value, T expected, char* message, std::experimental::source_location loc = std::experimental::source_location::current()) {
    if(value != expected) {
        std::stringstream ss;
        ss << "\033[1;31m" << message << "\033[0m" << std::endl;
        ss << std::hex << std::uppercase << "\033[1;36mExpected $" << +value << " to be $" << +expected << "\033[0m";
        ss << std::dec << " on \033[01;33m" << loc.file_name() << " line " << loc.line() << "\033[0m" << std::endl;
        std::cout << std::endl << ss.str();
        failed++;
    }
}

#endif
