
#include <gtest/gtest.h>
#include <vector>
#include "emallocator/emallocator.h"

TEST(EmallocatorTest, shouldWorkWithStrContainer) {
  {
    std::vector<int, phpex::emallocator<int>> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
  }
  EXPECT_TRUE(true);
}