#include "common.h"

TEST(gtest, test1) {
    std::cout << "hello gtest1" << std::endl;
}

TEST(gtest, test2) {
    std::cout << "hello gtest2" << std::endl;
}

TEST(gtest, test3) {
    std::cout << "hello gtest3" << std::endl;
}

void test_entry() {
    std::cout << "test_entry start" << std::endl;
}

TEST(gtest, test4) {
#pragma omp parallel
    test_entry();
}
