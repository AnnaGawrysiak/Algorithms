/*
Given an integer array, find the maximum length subarray having a given sum.
e.g.
A[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 }
Sum = 8

Subarrays with sum 8 are

{ -5, 5, 3, 5 }
{ 3, 5 }
{ 5, 3 }

The longest subarray is { -5, 5, 3, 5 } having length 4
*/


#include <iostream>
#include <unordered_map>

int findMaxLenSubarray(int arr[], int S, int n);

int main()
{
    int arr[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
    int sum = 8;

    int length = sizeof(arr) / sizeof(arr[0]);

    findMaxLenSubarray(arr, sum, length);

    return 0;
}

int findMaxLenSubarray(int arr[], int S, int n)
{
    //a hash table having(sum, index) tuples.
    std::unordered_map<int, int> map;
    int sum = 0;
    int maxlen = 0;
    int ending_index = -1;


    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // when subarray starts from index '0'
        if (sum == S)
            maxlen = i + 1;
        // if the sum is seen for the first time, insert the sum with its
        // into the map
        if (map.find(sum) == map.end())
            map[sum] = i;

        if (map.find(sum - S) != map.end()) 
            if (maxlen < (i - map[sum - S]))
            {
                maxlen = i - map[sum - S];
                ending_index = i;
            }
            
    }


    return maxlen;
}

/*
Comment with example:

arr[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
S = 8;
Output is : [2, 5]

At index 5, sum would be [ 5, 6, -5, 5, 3, 5 ] = 19 and (sum - S) is
11 (19 - 8). This total is present in the map (it is formed by first two elements [5, 6]). 
So we can say that elements in between (including current element) [-5, 5, 3, 5] have desired sum.
*/