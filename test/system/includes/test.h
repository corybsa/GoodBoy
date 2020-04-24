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
    int testsFailed;
    int testsPassed;
    int testsTotal;
    char* white;
    char* red;
    char* cyan;
    char* yellow;
    char* green;
    char* magenta;

    Test();

    virtual void beforeAll() = 0;
    virtual void beforeEach() = 0;
    virtual void tearDown() = 0;

    void addTest(const std::function<void()>& func);
    void run();

    void expect(size_t value, size_t expected, char* message, std::experimental::source_location loc = std::experimental::source_location::current());
};

#endif
