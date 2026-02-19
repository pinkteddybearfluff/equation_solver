
/*
 2x + y + z = 5;
 4x - 6y = -2;
 -2x + 7y + 2z = 9;


2x1 + x2 + x3 = 5;
 4x1 - 6x2 = -2;
 -2x1 + 7x2 + 2x3 = 9;

2one + two + three = 5;
4one - 6two = -2;
-2one + 7two + 2three = 9;
 ans = 1, 1, 2

 x + y = 3;
 x - y = 5;
 ans = 4, -1
 */

#include <iostream>
#include <string>
#include <vector>
#include "matrix_utilities.h"
#include "equation_parser.h"
#include "facilities.h"

using namespace std;


int main()
{
    try
    {
        int n_unk, n_eq;
        cout << "Enter system of equations for which number of unknowns is equal to number of equations.\n";
        cout << "Enter number of equations:";
        cin >> n_unk;
        n_eq = n_unk;
        if (!cin || n_unk <= 0)
        {
            error("expected a non-zero integer");
        }

        vector<vector<double>> matrix(n_eq, vector<double>(n_unk + 1));

        cout << "Enter system of linear equations terminated by a semicolon(;) :\n";
        //Gives augmented matrix as well as unknowns
        systemOfEq equations = equation_parser(n_eq, n_unk);

        //Apply gaussian elimination on augmented matrix to form lower triangular matrix
        apply_gaussian(n_unk, n_eq, equations.matrix);

        //Apply Jordan elimination on augmented matrix to form Identity like matrix
        apply_jordan(n_unk, n_eq, equations.matrix);

        print_matrix(equations.matrix);

        for (int i = 0; i < equations.var_table.size(); i++)
        {
            cout << equations.var_table[i] << " = " << equations.matrix[i][n_unk] << '\n';
        }
        return 0;
    }
    catch (exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch (InconsistentSystem)
    {
        cerr << "The system of linear equations is inconsistent.\n";
        return 2;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
    }
}

