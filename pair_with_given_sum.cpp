/*
Given an unsorted integer array, find a pair having a guven sum in it.

e.g.
Input:

arr = [8, 7, 2, 5, 3, 1]
sum = 10

Output:

Pair found (8, 2)
or
Pair found (7, 3)


Input:

arr = [5, 2, 6, 8, 1, 9]
sum = 12

Output: Pair not found
*/

#include <iostream>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> search(int arr[], int size, int sum);

int main()
{
    int arr[] = { 8, 7, 2, 5, 3, 1 };
    int sum = 10;
    int dimension = sizeof(arr) / sizeof(arr[0]);

    vector<pair<int, int>> pairs = search(arr, dimension, sum);

    for (std::vector<pair<int, int>>::const_iterator iter = pairs.begin(); iter != pairs.end(); ++iter)
    {
        cout << "Found pair: " << iter->first << " " << iter->second << std::endl;
    }

    return 0;
}

vector<pair<int, int>> search(int arr[], int size, int sum)
{
    vector<pair<int, int>> found_pairs;

    unordered_map <int, int> map;

    for (int i = 0; i < size; i++)
    {
        map[arr[i]] = i;

        if (map.find(sum - arr[i]) != map.end())
        {
            found_pairs.push_back(make_pair(arr[i], arr[map[sum - arr[i]]]));
        }
   
    }

    return found_pairs;
}