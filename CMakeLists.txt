cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    emallocator
    VERSION 0.1.0
    DESCRIPTION "Allocator implementation for use in PHP Extension."
    HOMEPAGE_URL "https://github.com/AlexeyKamenew/php-emallocator"
    LANGUAGES NONE
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(emallocator_emallocator INTERFACE)
add_library(emallocator::emallocator ALIAS emallocator_emallocator)

set_property(
    TARGET emallocator_emallocator PROPERTY
    EXPORT_NAME emallocator
)

target_include_directories(
    emallocator_emallocator ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(emallocator_emallocator INTERFACE cxx_std_17)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT emallocator_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of emallocator"
  )
endif()

include(cmake/dev-mode.cmake)
