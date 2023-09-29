#include <iostream>
#include <vector>

int cheapPath(const std::vector<std::vector<int>> &matrix, int row = 0, int col = 0, int total = 0)
{
    // If it goes outside the matrix:
    if (row == matrix.size() || col == matrix[row].size())
    {
        return -1;
    }
    // If it reaches a 0:
    if (matrix[row][col] == 0)
    {
        return -1;
    }

    total += matrix[row][col];
    // If it reaches the end.
    if (row == (matrix.size() - 1) && col == (matrix[row].size() - 1))
    {
        return total;
    }

    int right = cheapPath(matrix, row, col + 1, total);
    int down = cheapPath(matrix, row + 1, col, total);

    // If both sides return -1:
    if (right == -1 && down == -1)
    {
        return -1;
    }
    // If only one of the sides returns -1:
    if (right == -1 || down == -1)
    {
        if (right == -1)
        {
            return down;
        }
        if (down == -1)
        {
            return right;
        }
    }
    // Finding the minimum:
    if (right < down)
    {
        return right;
    }
    else
    {
        return down;
    }
}

int main()
{
    std::vector<std::vector<int>> matrix(5, std::vector<int>(5));
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 4;
    matrix[0][3] = 0;
    matrix[0][4] = 4;

    matrix[1][0] = 4;
    matrix[1][1] = 3;
    matrix[1][2] = 3;
    matrix[1][3] = 2;
    matrix[1][4] = 4;

    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
    matrix[2][3] = 2;
    matrix[2][4] = 1;

    matrix[3][0] = 1;
    matrix[3][1] = 0;
    matrix[3][2] = 2;
    matrix[3][3] = 2;
    matrix[3][4] = 1;

    matrix[4][0] = 1;
    matrix[4][1] = 4;
    matrix[4][2] = 2;
    matrix[4][3] = 3;
    matrix[4][4] = 2;

    std::vector<std::vector<int>> matrix2{
        {2, 2, 7, 0, 4},
        {4, 0, 0, 2, 4},
        {0, 1, 1, 2, 1}};

    std::cout << cheapPath(matrix) << std::endl;
    std::cout << cheapPath(matrix2) << std::endl;
}