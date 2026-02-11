//
// Created by wcosmo on 2/11/26.
//

#ifndef MATRIXSUITE_FACILITIES_H
#define MATRIXSUITE_FACILITIES_H

#include <string>

inline void error(const std::string& s)
{
    throw std::runtime_error(s);
}
#endif //MATRIXSUITE_FACILITIES_H
