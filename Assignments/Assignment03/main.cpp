#include <iostream>
#include <fstream>
#include <vector>

void printMatrix(const std::vector<std::vector<int>> &matrix)
{
    for (auto &row : matrix)
    {
        for (auto &x : row)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}
void printMatrix(const std::vector<std::vector<char>> &matrix)
{
    for (auto &row : matrix)
    {
        for (auto &x : row)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

void findZero(const std::vector<std::vector<int>> &matrix, std::vector<int> &start)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                start[0] = i;
                start[1] = j;
                return;
            }
        }
    }
}

bool zeroToZero(const std::vector<std::vector<int>> &matrix, std::vector<std::vector<char>> &map, const std::vector<int> &start, int row, int col, int total = 0)
{
    // std::cout << "Exploring cell [" << row << "][" << col << "] with total = " << total << std::endl; // Test.

    if (row == matrix.size() || col == matrix[row].size()) // If the path goes out of bounds.
        return false;
    if (map[row][col] != '-') // If the path crashes against itself.
        return false;

    if (matrix[row][col] == 0 && total > 0 && !(row == start[0] && col == start[1])) // If the path finds a zero.
        return true;

    total += matrix[row][col]; // Adding the value of the current cell.

    // Searching all directions.
    bool up = zeroToZero(matrix, map, start, row - 1, col, total);
    bool down = zeroToZero(matrix, map, start, row + 1, col, total);
    bool right = zeroToZero(matrix, map, start, row, col + 1, total);
    bool left = zeroToZero(matrix, map, start, row, col - 1, total);
    if (up || down || right || left)
    {

        if (row == start[0] && col == start[1]) // If its at the start.
        {
            if (up)
            {
                map[row][col] = 'N';
                return true;
            }
            if (down)
            {
                map[row][col] = 'S';
                return true;
            }
            if (right)
            {
                map[row][col] = 'E';
                return true;
            }
            if (left)
            {
                map[row][col] = 'W';
                return true;
            }
        }
        else // If its NOT at the start.
        {

            if (up)
            {
                map[row][col] = '^';
                return true;
            }
            if (down)
            {
                map[row][col] = 'v';
                return true;
            }
            if (right)
            {
                map[row][col] = '>';
                return true;
            }
            if (left)
            {
                map[row][col] = '<';
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // Getting file name.
    std::ifstream inputFile;
    std::string filename;
    std::cout << "Enter input file name: ";
    std::cin >> filename;
    inputFile.open(filename);

    if (!inputFile.is_open()) // If the program can't read the from the file.
    {
        std::cout << "Unable to read from file";
        return 1;
    }
    else // If the program CAN read from the file.
    {
        // Reading the matrix dimentions.
        int rows, cols;
        inputFile >> rows >> cols;

        // Creating a copy of the matrix.
        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                inputFile >> matrix[i][j];
            }
        }

        // Finding the start coordinates.
        std::vector<int> start = {0, 0};
        findZero(matrix, start);

        // Creating map/answer matrix.
        std::vector<std::vector<char>> map(rows, std::vector<char>(cols));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                map[i][j] = '-';
            }
        }

        // Finding path.
        bool result = zeroToZero(matrix, map, start, start[0], start[1]);

        // Displaying results.
        std::cout << "OG matrix" << std::endl;
        printMatrix(matrix);
        if (result)
        {
            std::cout << "Path matrix" << std::endl;
            printMatrix(map);
        }
        else
            std::cout << "No path found" << std::endl;
    }
}