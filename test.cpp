//
// Created by wcosmo on 2/19/26.
//

#include "matrix_utilities.h"
#include <iostream>

using namespace std;

int main()
{
    vector<vector<double>> matrix = {
        {1, 3, -2, 2, 3}, {1, 4, -3, 4, 2}, {2, 3, -1, -2, 9}, {1, 3, 0, 2, 1}, {1, 5, -6, 6, 3}, {2, 5, 3, 2, 1}
    };

    // vector<vector<double>> matrix = {
    //     {1, 1, 2, 0}, {3, 4, 3, 0}, {-2, -3, -1, 0}, {2, 4, -2, 0}, {3, 2, 9, 0}
    // };
    // vector<vector<double>> matrix = {{1, 3, -2, 2, 3, 0}, {1, 4, -3, 4, 2, 0}, {2, 3, -1, -2, 9, 0}};
    // vector<vector<double>> matrix = {{1, 3, 0, 2, 1}, {1, 5, -6, 6, 3}, {2, 5, 3, 2, 1}};

    // vector<vector<double>> matrix = {
    //     {1, -1, -1, 0, 0}, {4, -2, 0, 0, 1}, {6, -1, 0, -1, 0}, {9, -3, 1, 0, 0}, {2, -1, 0, 1, 0}, {4, -2, 0, 0, 1}
    // };

    // vector<vector<double>> matrix = {
    //     {-9, 3, 1, 0, 0, 0}, {4, -2, 0, 0, 1, 0}, {2, -1, 0, 1, 0, 0}, {-1, 1, 1, 0, 0, 0}, {4, -2, 0, 0, 1, 0},
    //     {-6, 1, 0, 1, 0, 0}
    // };
    print_matrix(matrix);
    apply_gauss_f_singular(matrix);
    // apply_jordan_f_singular(matrix);
    cout << "Reduced Row echelon form of matrix:\n";
    print_matrix(matrix);

    return 0;
}
