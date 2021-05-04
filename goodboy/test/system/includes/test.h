#ifndef GOODBOY_TEST_H
#define GOODBOY_TEST_H

#include <vector>
#include <functional>
#include "../../../system/includes/types.h"
#include <iostream>
#include <sstream>

class Test {
public:
    std::vector<std::function<void()>> tests;
    int testsFailed;
    int testsPassed;
    int testsTotal;
    std::stringstream testResults;
    const char* white;
    const char* red;
    const char* cyan;
    const char* yellow;
    const char* green;
    const char* magenta;

    Test();

    virtual void beforeAll() = 0;
    virtual void beforeEach() = 0;
    virtual void tearDown() = 0;

    void addTest(const std::function<void()>& func);
    void run(std::string* results);

    void expect(unsigned long long value, unsigned long long expected, const char* message);
};

#endif
