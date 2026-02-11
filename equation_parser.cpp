//
// Created by wcosmo on 2/11/26.
//

#include "equation_parser.h"

//returns a string with only alphabet and digits
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

//checks if an unknown is new or old
bool is_unique(string var_name, vector<string>& var_table)
{
    for (const string& var : var_table)
    {
        if (var == var_name)
        {
            return false;
        }
    }
    return true;
}

//get column number for the respective variable name in order of declaration
int get_colv(string var_name, vector<string>& var_table)
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
    vector<vector<double>> matrix(n_eq, vector<double>(n_unk + 1));
    vector<string> var_table;

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
            cin >> rhs;
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
    }

    systemOfEq equations;
    equations.var_table = var_table;
    equations.matrix = matrix;
    return equations;
}
