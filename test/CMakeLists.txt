cmake_minimum_required(VERSION 3.14)

project(emallocatorTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)
include(../cmake/windows-set-path.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(emallocator REQUIRED)
  enable_testing()
endif()

set(GTEST_VERSION 1.12.1 CACHE STRING "Google test version")

Include(FetchContent)
FetchContent_Declare(googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG release-${GTEST_VERSION})
FetchContent_MakeAvailable(googletest)

# ---- Tests ----

add_executable(emallocator_test source/emallocator_test.cc)
target_link_libraries(emallocator_test PRIVATE emallocator::emallocator GTest::gtest_main)
target_include_directories(emallocator_test PRIVATE include/)
target_compile_features(emallocator_test PRIVATE cxx_std_17)

include(GoogleTest)
gtest_discover_tests(emallocator_test)

# ---- End-of-file commands ----

add_folders(Test)
