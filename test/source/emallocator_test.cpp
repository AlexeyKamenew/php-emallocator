
#include <gtest/gtest.h>
#include <vector>
#include "test_zend_alloc.h"
#include "emallocator/emallocator.hpp"

TEST(EmallocatorTest, shouldWorkWithStrContainer) {
  std::vector<int, phpex::emallocator<int>> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  EXPECT_TRUE(true);
}