#ifndef MATRIXSUITE_FACILITIES_H
#define MATRIXSUITE_FACILITIES_H

#include <iostream>
#include <string>

inline void error(const std::string& s)
{
    throw std::runtime_error(s);
}
#endif //MATRIXSUITE_FACILITIES_H
