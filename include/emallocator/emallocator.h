#pragma once

#include <cstdlib>  // size_t
#include <new>      // bad_array_new_length

#include "php.h"

namespace phpex {

template <typename T>
class emallocator {
  public:
  using value_type = T;
  
  emallocator() noexcept = default;

  template <typename U>
  explicit emallocator(const emallocator<U>&) noexcept { }

  T* allocate(std::size_t size) const {
    if (size == 0) {
      return nullptr;
    }


    if (size > static_cast<std::size_t>(-1) / sizeof(T)) {
      throw std::bad_array_new_length();
    }

    return static_cast<T*>(emalloc(size * sizeof(T)));
    // Note: Unlike their C standard library's counterparts 
    // the Zend Engine's memory management functions won't return NULL 
    // in case of an problem while allocating the requested memory 
    // but bail out and terminate the current request.
    // So, there is neither check no bad_alloc throw.
  }

  void deallocate(T* ptr, [[maybe_unused]]std::size_t size = 0) {
    efree(ptr);
  }

  template <typename U>
  bool operator==(const emallocator<U>&) const { return true; }
  
  template <typename U>
  bool operator!=(const emallocator<U>&) const { return false; }

};

}