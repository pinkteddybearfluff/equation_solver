//
// Created by wcosmo on 2/2/26.
//

#ifndef MATRIXSUITE_MATRIX_UTILITIES_H
#define MATRIXSUITE_MATRIX_UTILITIES_H


#include <vector>
#include <iostream>

using namespace std;

void apply_gaussian(int no_of_unknowns, int no_of_equations, std::vector<std::vector<double>>& matrix);
void apply_jordan(int no_of_unknowns, int no_of_equations, std::vector<std::vector<double>>& matrix);
void print_matrix(const std::vector<std::vector<double>>& matrix);


void apply_gaussian(int n_unk, int n_eq, vector<vector<double>>& matrix)
{
    for (int i = 0; i < n_eq; ++i)
    {
        //check if pivot is non-zero
        if (matrix[i][i] == 0)
        {
            for (int j = i + 1; j < n_eq; ++j)
            {
                if (matrix[j][i] != 0)
                {
                    //swap rows
                    for (int k = i; k < n_unk + 1; k++)
                    {
                        const double tmp = matrix[j][k];
                        matrix[j][k] = matrix[i][k];
                        matrix[i][k] = tmp;
                    }
                }
            }
        }

        for (int j = i + 1; j < n_eq; ++j)
        {
            const double multiplier = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n_unk + 1; k++)
            {
                matrix[j][k] = matrix[j][k] - matrix[i][k] * multiplier;
            }
        }
    }
}

void apply_jordan(int n_uk, int n_eq, vector<vector<double>>& matrix)
{
    for (int i = n_eq - 1; i >= 0; --i)
    {
        double pivot = matrix[i][i];
        for (int j = i - 1; j >= 0; --j)
        {
            double multiplier = matrix[j][i] / pivot;
            for (int k = i; k < n_uk + 1; k++)
            {
                matrix[j][k] = matrix[j][k] - matrix[i][k] * multiplier;
            }
        }
        for (int j = i; j < n_uk + 1; j++)
        {
            matrix[i][j] /= pivot;
        }
    }
}

void print_matrix(const vector<vector<double>>& matrix)
{
    for (const vector<double>& row : matrix)
    {
        for (const double num : row)
        {
            cout << num << "\t";
        }
        cout << '\n';
    }
}

#endif //MATRIXSUITE_MATRIX_UTILITIES_H
