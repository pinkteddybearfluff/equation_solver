#ifndef MATRIXSUITE_EQUATION_PARSER_H
#define MATRIXSUITE_EQUATION_PARSER_H

#include <vector>
#include <iostream>
#include "facilities.h"

class systemOfEq
{
public:
    std::vector<std::string> var_table;
    std::vector<std::vector<double>> matrix;
};


std::string get_string();
bool is_unique(std::string var_name, std::vector<std::string>& var_table);
int get_colv(std::string var_name, std::vector<std::string>& var_table);
systemOfEq equation_parser(int n_eq, int n_unk);
std::vector<std::string> get_free_variables(systemOfEq);
std::vector<std::vector<double>> get_independent_vectors(systemOfEq equations);

#endif //MATRIXSUITE_EQUATION_PARSER_H
