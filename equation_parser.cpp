#include "equation_parser.h"

//returns a string with only alphabet and digits
std::string get_string()
{
    char ch;
    std::string my_string;
    while (std::cin)
    {
        std::cin >> ch;
        if (!isalpha(ch) && !isdigit(ch))
        {
            std::cin.putback(ch);
            return my_string;
        }
        my_string.push_back(ch);
    }
    return my_string;
}

//checks if an unknown is new or old
bool is_unique(std::string var_name, std::vector<std::string>& var_table)
{
    for (const std::string& var : var_table)
    {
        if (var == var_name)
        {
            return false;
        }
    }
    return true;
}

//get column number for the respective variable name in order of declaration
int get_colv(std::string var_name, std::vector<std::string>& var_table)
{
    for (int i = 0; i < var_table.size(); i++)
    {
        if (var_table[i] == var_name)
        {
            return i;
        }
    }
    error("Unknown variable name");
}

//read equations character by character
systemOfEq equation_parser(int n_eq, int n_unk)
{
    //Augmented matrix
    std::vector<std::vector<double>> matrix(n_eq, std::vector<double>(n_unk + 1));
    std::vector<std::string> var_table;

    char ch;
    bool has_coeff;
    int sign = 1;
    double coeff;
    std::string var_name;
    int equation_no = 0;
    while (equation_no < n_eq)
    {
        std::cin >> ch;
        if (ch == '+')
        {
            sign = 1;
        }
        else if (ch == '-')
        {
            sign = -1;
        }
        else if (isdigit(ch))
        {
            std::cin.putback(ch);
            std::cin >> coeff;
            has_coeff = true;
        }
        else if (isalpha(ch))
        {
            std::cin.putback(ch);
            var_name = get_string();

            //Variable declaration for new variable
            if (is_unique(var_name, var_table))
            {
                var_table.push_back(var_name);
            }

            if (has_coeff)
            {
                matrix[equation_no][get_colv(var_name, var_table)] = sign * coeff;
            }
            else
            {
                matrix[equation_no][get_colv(var_name, var_table)] = sign;
            }
            sign = 1;
            has_coeff = false;
        }
        else if (ch == ';')
        {
            ++equation_no;
            if (var_table.empty())
            {
                error("expected at least one variable");
            }
        }
        else if (ch == '=')
        {
            int rhs;
            std::cin >> rhs;
            matrix[equation_no][n_unk] = rhs;
        }
        else if (isspace(ch)) { continue; }
        else
        {
            error("unknown character");
        }

        if (var_table.size() > n_unk)
        {
            error("Too many variables than expected");
        }
        // else if (var_table.size() == 0)
        // {
        //     error("expected at least one variable");
        // }
    }

    systemOfEq equations;
    equations.var_table = var_table;
    equations.matrix = matrix;
    return equations;
}

std::vector<std::string> get_free_variables(systemOfEq equations)
{
    std::vector<std::string> free_variables;
    std::vector<std::string> var_table = equations.var_table;
    std::vector<std::vector<double>> matrix = equations.matrix;
    for (int i = 0; i < matrix.size();)
    {
        for (int j = 0; j < matrix[0].size();)
        {
            if (i < matrix.size() && matrix[i][j] != 0)
            {
                i++;
                j++;
            }
            else
            {
                free_variables.push_back(var_table[j]);
                j++;
            }

            if (j == var_table.size())
            {
                return free_variables;
            }
        }
    }
    return free_variables;
}

std::vector<std::vector<double>> get_independent_vectors(systemOfEq equations)
{
    std::vector<std::vector<double>> independent_variables;
    std::vector<std::string> free_variables = get_free_variables(equations);
    std::vector<std::vector<double>> matrix = equations.matrix;
    std::vector<double> X(equations.var_table.size(), 0);
    for (int i = 0; i < free_variables.size(); i++)
    {
        bool pivot_exists = false;
        X[get_colv(free_variables[i], equations.var_table)] = 1;
        for (int j = matrix.size() - 1; j >= 0; j--)
        {
            for (int k = 0; k < matrix[0].size(); k++)
            {
                if (matrix[j][k] != 0 && !pivot_exists)
                {
                    pivot_exists = true;
                    double tmp_sum = 0;
                    for (int l = k + 1; l < matrix[0].size() - 1; l++)
                    {
                        tmp_sum += matrix[j][l] * X[l];
                    }
                    X[k] = matrix[j][matrix[0].size() - 1] - tmp_sum;
                }
            }
            pivot_exists = false;
        }
        independent_variables.push_back(X);

        //reset vector X
        for (double& var_value : X)
        {
            var_value = 0;
        }
    }
    return independent_variables;
}
