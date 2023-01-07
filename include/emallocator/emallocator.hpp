#pragma once

#include <cstdlib>
//#include <Zend/zend_alloc.h>

namespace phpex {

template <typename T>
class emallocator {
  public:
  using value_type = T;
  
  emallocator() noexcept { }

  template <typename U>
  emallocator(const emallocator<U>&) noexcept { }

  T* allocate(std::size_t size) const {
    if (size == 0)
      return nullptr;

    if (size > static_cast<std::size_t>(-1) / sizeof(T))
      throw std::bad_array_new_length();

    void* ptr = nullptr;
    ptr = emalloc(size * sizeof(T));
    if (ptr)
      return static_cast<T*>(ptr);

    throw std::bad_alloc();
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