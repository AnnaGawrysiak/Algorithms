/*
Print a given matrix in spiral form.
*/

#include <iostream>
#include <vector>

void print_spiral(const std::vector<std::vector<int>>& matrix);

int main()
{
    std::vector<std::vector<int>> my_matrix = { {9, 9, 7, 1, 3},
                                          { 9, 7, 2, 4, 3},
                                          { 6, 9, 5, 5, 5},
                                          { 9, 1, 2, 6, 8} };

    print_spiral(my_matrix);

    return 0;
}

void print_spiral(const std::vector<std::vector<int>>& matrix)
{
    int top = 0;
    int down = matrix.size() - 1;
    int left = 0;
    int right = matrix.at(0).size() - 1;
    int direction = 0; // 0 - left to right, 1 - from top to down, 2 - move from right to left, 3 - from the bottom to the top

    while (top <= down && left <= right)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; i++)
            {
                std::cout << matrix[top][i] << " ";
            }
            top++;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= down; i++)
            {
                std::cout << matrix[i][right] << " ";
            }
            right--;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; i--)
            {
                std::cout << matrix[down][i] << " ";
            }
            down--;
        }
        else if (direction == 3)
        {
            for (int i = down; i >= top; i--)
            {
                std::cout << matrix[i][left] << " ";
            }
            left++;
        }

        direction = (direction + 1) % 4;
    }
}