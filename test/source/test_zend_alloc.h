#pragma once

#include <cstdlib>

void *emalloc(std::size_t size) {
    return malloc(size);
}

void efree(void *ptr) {
    free(ptr);
}