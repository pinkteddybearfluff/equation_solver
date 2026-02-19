#ifndef MATRIXSUITE_EQUATION_PARSER_H
#define MATRIXSUITE_EQUATION_PARSER_H


#include <vector>
#include "facilities.h"
using namespace std;

class systemOfEq
{
public:
    vector<string> var_table;
    vector<vector<double>> matrix;
};


string get_string();
bool is_unique(string var_name, vector<string>& var_table);
int get_colv(string var_name, vector<string>& var_table);
systemOfEq equation_parser(int n_eq, int n_unk);


#endif //MATRIXSUITE_EQUATION_PARSER_H
