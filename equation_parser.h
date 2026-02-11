//
// Created by wcosmo on 2/5/26.
//

#ifndef MATRIXSUITE_EQUATION_PARSER_H
#define MATRIXSUITE_EQUATION_PARSER_H


#include <iostream>
#include <vector>
using namespace std;

class sys_of_leq
{
public:
    vector<string> var_table;
    vector<vector<double>> matrix;
};


vector<string> var_table;

string get_string();
bool is_unique(string var_name);
int get_col(const char var_name);
int get_colv(string var_name);
sys_of_leq equation_parser(int n_eq, int n_unk);


string get_string()
{
    char ch;
    string my_string;
    while (cin)
    {
        cin >> ch;
        if (!isalpha(ch) && !isdigit(ch))
        {
            cin.putback(ch);
            return my_string;
        }
        my_string.push_back(ch);
    }
    return my_string;
}

bool is_unique(string var_name)
{
    for (string var : var_table)
    {
        if (var == var_name)
        {
            return false;
        }
    }
    return true;
}

int get_colv(string var_name)
{
    for (int i = 0; i < var_table.size(); i++)
    {
        if (var_table[i] == var_name)
        {
            return i;
        }
    }
}

//Todo: may be instead of returning a matrix vector i can return a user defined type which has both matrix vector and variables vector.

sys_of_leq equation_parser(int n_eq, int n_unk)
{
    vector<vector<double>> matrix(n_eq, vector<double>(n_unk + 1));

    char ch;
    bool has_coeff;
    int sign = 1;
    double coeff;
    string var_name;
    int equation_no = 0;
    while (equation_no < n_eq)
    {
        cin >> ch;
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
            cin.putback(ch);
            cin >> coeff;
            has_coeff = true;
        }
        else if (isalpha(ch))
        {
            cin.putback(ch);
            var_name = get_string();
            if (is_unique(var_name))
            {
                var_table.push_back(var_name);
            }
            if (has_coeff)
            {
                matrix[equation_no][get_colv(var_name)] = sign * coeff;
            }
            else
            {
                matrix[equation_no][get_colv(var_name)] = sign;
            }
            sign = 1;
            has_coeff = false;
        }
        else if (ch == ';')
        {
            ++equation_no;
        }
        else if (ch == '=')
        {
            int rhs;
            cin >> rhs;
            matrix[equation_no][3] = rhs;
        }
    }

    sys_of_leq equa;
    equa.var_table = var_table;
    equa.matrix = matrix;
    return equa;
}

#endif //MATRIXSUITE_EQUATION_PARSER_H
