//
// Created by wcosmo on 2/1/26.
//

/*
 2x + y + z = 5;
 4x - 6y = -2;
 -2x + 7y + 2z = 9;


2x1 + x2 + x3 = 5;
 4x1 - 6x2 = -2;
 -2x1 + 7x2 + 2x3 = 9;
 */

#include <iostream>
#include <string>
#include <vector>
#include "matrix_utilities.h"
#include "equation_parser.h"

using namespace std;

void error(string s);

int main()
{
    int n_unk = 3, n_eq = 3;
    cout << "Enter number of unknowns:";
    cin >> n_unk;
    cout << "Enter number of equations";
    cin >> n_eq;
    vector<vector<double>> matrix(n_eq, vector<double>(n_unk + 1));
    // ans: { 1, 1, 2}
    matrix = {
        {2, 1, 1, 5},
        {4, -6, 0, -2},
        {-2, 7, 2, 9}
    };

    sys_of_leq systema = equation_parser(n_eq, n_unk);

    apply_gaussian(n_unk, n_eq, systema.matrix);
    apply_jordan(n_unk, n_eq, systema.matrix);

    print_matrix(systema.matrix);
    for (int i = 0; i < systema.var_table.size(); i++)
    {
        cout << systema.var_table[i] << " = " << systema.matrix[i][n_unk] << '\n';
    }
    return 0;
}

void error(const string& s)
{
    throw runtime_error(s);
}
