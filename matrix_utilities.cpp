#include "matrix_utilities.h"

int apply_gaussian(int n_unk, int n_eq, std::vector<std::vector<double>>& matrix)
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

        if (matrix[i][i] == 0)
        {
            if (matrix[i][i + 1] != 0)
            {
                std::cout << "System has no solution. \n";
                throw InconsistentSystem();
            }
            return -1;
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
    return 0;
}

void apply_gauss_f_singular(std::vector<std::vector<double>>& matrix)
{
    for (int i = 0, m = 0; i < matrix.size();)
    {
        if (m >= matrix[0].size())
        {
            return;
        }

        //check if pivot is non-zero
        if (matrix[i][m] == 0)
        {
            for (int j = i + 1; j < matrix.size(); ++j)
            {
                if (matrix[j][i] != 0)
                {
                    //swap rows
                    for (int k = i; k < matrix[0].size(); k++)
                    {
                        const double tmp = matrix[j][k];
                        matrix[j][k] = matrix[i][k];
                        matrix[i][k] = tmp;
                    }
                }
            }
        }

        if (matrix[i][m] == 0)
        {
            ++m;
            continue;
        }
        for (int j = i + 1; j < matrix.size(); ++j)
        {
            const double multiplier = matrix[j][m] / matrix[i][m];
            for (int k = i; k < matrix[0].size(); k++)
            {
                matrix[j][k] = matrix[j][k] - matrix[i][k] * multiplier;
            }
        }
        ++i;
        ++m;
    }
}

void apply_jordan_f_singular(std::vector<std::vector<double>>& matrix)
{
    bool pivot_exists = false;
    for (int i = matrix.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] != 0 && !pivot_exists)
            {
                pivot_exists = true;
                double pivot = matrix[i][j];
                for (int k = i - 1; k >= 0; --k)
                {
                    double multiplier = matrix[k][j] / pivot;
                    for (int l = j; l < matrix[0].size(); l++)
                    {
                        matrix[k][l] = matrix[k][l] - matrix[i][l] * multiplier;
                    }
                }
                for (int m = j; m < matrix[0].size(); ++m)
                {
                    matrix[i][m] /= pivot;
                }
            }
        }
        pivot_exists = false;
    }
}

void apply_jordan(int n_uk, int n_eq, std::vector<std::vector<double>>& matrix)
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

void print_matrix(const std::vector<std::vector<double>>& matrix)
{
    for (const std::vector<double>& row : matrix)
    {
        for (const double num : row)
        {
            std::cout << num << "\t";
        }
        std::cout << '\n';
    }
}
