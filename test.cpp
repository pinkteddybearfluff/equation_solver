//
// Created by wcosmo on 2/19/26.
//

#include "matrix_utilities.h"
#include <iostream>


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
