#ifndef GOODBOY_TEST_H
#define GOODBOY_TEST_H

#include <vector>
#include <functional>
#include "../../../src/system/includes/types.h"

class Test {
public:
    std::vector<std::function<void()>> tests;
    int failed;

    Test();

    virtual void beforeAll() = 0;
    virtual void beforeEach() = 0;

    void addTest(std::function<void()> func);
    void run();

    void expect(byte value, byte expected, char* message);
    void expect(word value, word expected, char* message);
    void expect(bool value, bool expected, char* message);
};

#endif
