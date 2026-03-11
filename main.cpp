
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

x + 2y + z -2t = 0;
2x + 4y + 4z -3t =0;
3x + 6y + 7z -4t =0;

u,v,w,y
u + 3v + 3w + 2y = 0;
2u + 6v + 9w + 7y = 0;
-u - 3v + 3w + 4y = 0;

x1 + 2x2 + 3x3 + 5x4 = 0;
2x1 + 4x2 + 8x3 + 12x4 = 0;
3x1 + 6x2 + 7x3 + 13x4 = 0;


HW:
-x + y + z = 0;
4x -2y + t = 0;
-6x + y + s = 0;
9x -3y - z = 0;
4x - 2y + t = 0;
2s - t = 0;
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "equation_parser.h"
#include "facilities.h"
#include "matrix_utilities.h"

using namespace std;


int main()
{
    try
    {
        int n_unk, n_eq;
        cout << "Enter system of equations for which number of unknowns is equal to number of equations.\n";
        cout << "Enter number of equations: ";
        cin >> n_eq;
        cout << "Enter number of unknowns: ";
        cin >> n_unk;
        if (!cin || n_unk <= 0)
        {
            error("expected a non-zero integer");
        }

        vector<vector<double>> matrix(n_eq, vector<double>(n_unk + 1));

        cout << "Enter system of linear equations terminated by a semicolon(;) :\n";
        //Gives augmented matrix as well as unknowns
        systemOfEq equations = equation_parser(n_eq, n_unk);

        //Apply gaussian elimination on augmented matrix to form lower triangular matrix
        apply_gauss_f_singular(equations.matrix);
        apply_jordan_f_singular(equations.matrix);

        vector<string> free_variables = get_free_variables(equations);
        for (string free_variable : free_variables)
        {
            cout << free_variable << endl;
        }

        print_matrix(equations.matrix);
        vector<vector<double>> independent_vectors = get_independent_vectors(equations);
        cout << "A Basis of solution space:\n";
        for (int i = 0; i < equations.var_table.size(); i++)
        {
            for (int j = 0; j < independent_vectors.size(); j++)
            {
                cout << setw(4) << '|' << independent_vectors[j][i] << " ";
            }
            cout << '|';
            cout << '\n';
        }
        cout << "The Dimension of solution space or Nullity is " << independent_vectors.size() << '\n';
        //Apply Jordan elimination on augmented matrix to form Identity like matrix
        // apply_jordan(n_unk, n_eq, equations.matrix);

        // print_matrix(equations.matrix);

        // for (int i = 0; i < equations.var_table.size(); i++)
        // {
        //     cout << equations.var_table[i] << " = " << equations.matrix[i][n_unk] << '\n';
        // }
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

