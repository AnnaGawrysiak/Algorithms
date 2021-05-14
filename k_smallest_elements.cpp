#include <iostream>
#include <vector>
#include <queue>
#include <functional>

// C++ program to use priority_queue to implement min heap

void print_k_smallest_elements(const int k, int size, int numbers[]);

// Driver code
int main()
{
    const int k = 3;
    int arr[] = { 11, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
    
    int size = sizeof(arr) / sizeof(arr[0]);

    print_k_smallest_elements(k, size, arr);

    return 0;
}


void print_k_smallest_elements(const int k, int size, int numbers[])
{
    // Creates a min heap
    std::priority_queue <int, std::vector<int>, std::greater<int> > priority_queue;

    for (int i = 0; i < size; i++)
    {
        priority_queue.push(numbers[i]);
    }

    for (int i = 0; i < k; i++)
    {
        std::cout << priority_queue.top() << " ";
        priority_queue.pop();
    }
}