#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "equation_parser.h"
#include "facilities.h"
#include "matrix_utilities.h"

int main()
{
    try
    {
        int n_unk, n_eq;
        std::cout << "Enter system of equations for which number of unknowns is equal to number of equations.\n";
        std::cout << "Enter number of equations: ";
        std::cin >> n_eq;
        std::cout << "Enter number of unknowns: ";
        std::cin >> n_unk;
        if (!std::cin || n_unk <= 0)
        {
            error("expected a non-zero integer");
        }

        std::vector<std::vector<double>> matrix(n_eq, std::vector<double>(n_unk + 1));

        std::cout << "Enter system of linear equations terminated by a semicolon(;) :\n";
        //Gives augmented matrix as well as unknowns
        systemOfEq equations = equation_parser(n_eq, n_unk);

        //Apply gaussian elimination on augmented matrix to form lower triangular matrix
        apply_gauss_f_singular(equations.matrix);
        apply_jordan_f_singular(equations.matrix);

        std::vector<std::string> free_variables = get_free_variables(equations);
        for (std::string free_variable : free_variables)
        {
            std::cout << free_variable << '\n';
        }

        print_matrix(equations.matrix);
        std::vector<std::vector<double>> independent_vectors = get_independent_vectors(equations);
        std::cout << "A Basis of solution space:\n";
        for (int i = 0; i < equations.var_table.size(); i++)
        {
            for (int j = 0; j < independent_vectors.size(); j++)
            {
                std::cout << std::setw(4) << '|' << independent_vectors[j][i] << " ";
            }
            std::cout << '|';
            std::cout << '\n';
        }
        std::cout << "The Dimension of solution space or Nullity is " << independent_vectors.size() << '\n';
        //Apply Jordan elimination on augmented matrix to form Identity like matrix
        // apply_jordan(n_unk, n_eq, equations.matrix);

        // print_matrix(equations.matrix);

        // for (int i = 0; i < equations.var_table.size(); i++)
        // {
        //     cout << equations.var_table[i] << " = " << equations.matrix[i][n_unk] << '\n';
        // }
        return 0;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch (InconsistentSystem)
    {
        std::cerr << "The system of linear equations is inconsistent.\n";
        return 2;
    }
    catch (...)
    {
        std::cerr << "unknown exception\n";
    }
}

