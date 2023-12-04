#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "stack.h"

struct point
{
    int row = 0;
    int col = 0;

    bool operator==(const point &other)
    {
        return row == other.row && col == other.col;
    }
};

/**
 * Store Values function.
 * Reads a matrix from a file and stores it in a multi-dimensional vector.
 *
 * @param m - multi-dimensional vector of integers.
 * @param fin - input file.
 * @param rows - integer, amount of rows.
 * @param cols - integer, colums.
 */
void storeValues(std::vector<std::vector<int>> &m, std::fstream &fin, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fin >> m[i][j];
}

/**
 * Print function.
 * Prints the values of a multi-dimentional vector.
 *
 * @param m - multi-dimensional vector.
 */
template <typename T>
void print(std::vector<std::vector<T>> &m)
{
    for (auto &row : m)
    {
        for (auto &x : row)
        {
            std::cout << std::setw(3) << x << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Path finder function.
 * Finds a zero in a matrix of integers and tries to find a positive path to another zero in the matrix.
 *
 * @param m - multi-dimensional vector of integers.
 */
void pathFinder(std::vector<std::vector<int>> &m)
{
    int rows = m.size();
    int cols = m[0].size();
    point start;
    bool flag = false;

    // Creating map matrix
    std::vector<std::vector<char>> map(rows, std::vector<char>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            map[i][j] = '-';
            if (m[i][j] == 0 && !flag)
            {
                start = {i, j};
                flag = true;
            }
        }

    int r = start.row,
        c = start.col,
        sum = 0;
    bool dir[] = {1, 1, 1, 1};
    stack<point> path;
    path.push(start);

    while (m[r][c] != 0 || (r == start.row && c == start.col))
    {
        // Moving spot
        if (dir[0])
        {
            if (path.peek() == start)
                map[r][c] = 'N';
            else
                map[r][c] = '^';
            r--;
        }
        else if (dir[1])
        {
            if (path.peek() == start)
                map[r][c] = 'E';
            else
                map[r][c] = '>';
            c++;
        }
        else if (dir[2])
        {
            if (path.peek() == start)
                map[r][c] = 'S';
            else
                map[r][c] = 'v';
            r++;
        }
        else if (dir[3])
        {
            if (path.peek() == start)
                map[r][c] = 'W';
            else
                map[r][c] = '<';
            c--;
        }
        else
        {
            // Blocked on all directions so the program has to retreat one spot
            point last = path.pop();
            if (path.isEmpty()) // tried all possible paths and found nothing
            {
                std::cout << "No path found" << std::endl;
                return;
            }
            r = path.peek().row;
            c = path.peek().col;
            sum -= m[last.row][last.col];
            dir[0] = true;
            dir[1] = true;
            dir[2] = true;
            dir[3] = true;

            map[r][c] = '-';
            if (last.row < r) // retreat down
                dir[0] = false;
            else if (last.col > c) // retreat left
                dir[1] = false;
            else if (last.row > r) // retreat up
                dir[2] = false;
            else // retreat right
                dir[3] = false;
            continue;
        }
        path.push({r, c});

        // if it goes outside the matrix:
        if (r < 0) // above the top
        {
            r++;
            map[r][c] = '-';
            path.pop();
            dir[0] = false;
        }
        else if (c == cols) // to the right
        {
            c--;
            map[r][c] = '-';
            path.pop();
            dir[1] = false;
        }
        else if (r == rows) // below the bottom
        {
            r--;
            map[r][c] = '-';
            path.pop();
            dir[2] = false;
        }
        else if (c < 0) // to the left
        {
            c++;
            map[r][c] = '-';
            path.pop();
            dir[3] = false;
        }
        else if (map[r][c] != '-' || (m[r][c] == 0 && sum < 1)) // crashed against a used spot, or a zero while the sum not positive
        {
            point last = path.pop();
            if (last.row < path.peek().row) // crashed above
            {
                r++;
                map[r][c] = '-';
                dir[0] = false;
            }
            else if (last.col > path.peek().col) // crashed right
            {
                c--;
                map[r][c] = '-';
                dir[1] = false;
            }
            else if (last.row > path.peek().row) // crashed below
            {
                r--;
                map[r][c] = '-';
                dir[2] = false;
            }
            else // crashed left
            {
                c++;
                map[r][c] = '-';
                dir[3] = false;
            }
        }
        else
        {
            sum += m[r][c];
            dir[0] = true;
            dir[1] = true;
            dir[2] = true;
            dir[3] = true;
        }
    }
    if (m[r][c] == 0)
    {
        map[r][c] = 'X';
    }

    print(map);
}

/**
 * Main function.
 *
 * @return 0, 1;
 */
int main()
{
    std::fstream fin;
    std::string filename;
    std::cout << "Enter input file name: ";
    std::cin >> filename;
    fin.open(filename);
    // fin.open("Matrix.txt");

    if (!fin.is_open())
    {
        std::cout << "Unable to read from a file";
        return 1;
    }
    else
    {
        int rows, cols;
        fin >> rows >> cols;
        std::vector<std::vector<int>> m(rows, std::vector<int>(cols));
        storeValues(m, fin, rows, cols);
        print(m);
        std::cout << std::endl;
        pathFinder(m);
    }

    fin.close();
    return 0;
}