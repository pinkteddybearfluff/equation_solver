#ifndef MATRIXSUITE_MATRIX_UTILITIES_H
#define MATRIXSUITE_MATRIX_UTILITIES_H


#include <vector>
#include "facilities.h"

using namespace std;

class InconsistentSystem
{
};

void apply_gaussian(int no_of_unknowns, int no_of_equations, std::vector<std::vector<double>>& matrix);
void apply_jordan(int no_of_unknowns, int no_of_equations, std::vector<std::vector<double>>& matrix);
void print_matrix(const std::vector<std::vector<double>>& matrix);


#endif //MATRIXSUITE_MATRIX_UTILITIES_H
