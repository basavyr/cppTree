#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cstdlib>

void newLine()
{
    //show a line
    std::cout << "\n";
}

void showDate()
{
    auto now = std::chrono::system_clock::now();
    std::time_t date = std::chrono::system_clock::to_time_t(now);
    std::cout << std::ctime(&date) << "\n";
}

void showUser(const std::string &name)
{
    std::cout << name << "\n";
    std::cout << " wishes you a happy holiday :)"
              << "\n";
}

void init(char *x)
{
    // std::cout << x << "\n";
    *x = '*';
}

void initmatrix(char *matrix, int nrows, int ncols)
{
    for (int i = 0; i < nrows; ++i)
    {
        for (int j = 0; j < ncols; ++j)
        {
            *((matrix + i * nrows) + j) = ' ';
        }
    }
}

void showTree(char *tree, int nrows, int ncols)
{
    for (int i = 0; i < nrows; ++i)
    {
        for (int j = 0; j < ncols; ++j)
        {
            // init(&(*((tree + i * nrows) + j)));
            std::cout << *((tree + i * ncols) + j) << " ";
        }
        std::cout << "\n";
    }
}

void drawTree(char *tree, int nrows, int ncols)
{
    int i, j;
    i = nrows - 1;
    j = ncols;
    int left = 0;
    while (i >= 0)
    {
        for (int index = left; index < j; ++index)
        {
            int matIndex = i * ncols + index;
            // std::cout << i << " " << index << "\n";
            init(tree + matIndex);
            // *(tree + matIndex) = 'x';
        }
        i--;
        j--;
        left++;
    }
}

int main()
{
    int nRows, nCols;
    nRows = 3;
    nCols = nRows * 2 - 1;
    char tree[nRows][nCols];
    // showTree(*tree, nRows, nCols);
    initmatrix(*tree, nRows, nCols);
    drawTree(*tree, nRows, nCols);
    // newLine();
    showTree(*tree, nRows, nCols);
    return 0;
}