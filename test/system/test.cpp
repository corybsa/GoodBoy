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
        std::cout << std::endl << "\033[1;32mAll tests passed!\033[0m" << std::endl;
    } else {
        std::cout << std::endl << +failed << " test" << (failed == 1 ? "" : "s") << " failed!" << std::endl;
    }
}
