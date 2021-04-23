#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector< pair<int, int> > FindSubArrays(int arr[], int size);
void print(vector <pair<int, int>> arrays);

int main()
{
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<pair<int, int>> subarrays = FindSubArrays(arr, n);

    print(subarrays);

    return 0;
}

vector< pair<int, int> > FindSubArrays(int arr[], int arr_size)
{
    // a map stores sum of subsequent array elements
    unordered_map<int, vector<int>> map;

    // create an empty vector of pairs to store
    // subarray starting and ending index
    vector<pair<int, int>> subarrays;

    int sum = 0;

    for (int i = 0; i < arr_size; i++)
    {
        sum+= arr[i];

        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if(sum == 0)
            subarrays.push_back(make_pair(0, i));
        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if(map.find(sum) != map.end())
        {
           // map[sum] stores starting index of all subarrays
            vector<int> starting_index = map[sum];

            for(auto it = starting_index.begin(); it != starting_index.end(); it++)
            {
                subarrays.push_back(make_pair(*it+1, i));
            }
        }


        // Important - always add a new index to the map
        map[sum].push_back(i);
    }

    return subarrays;
}

void print(vector <pair<int, int>> arrays)
{
    for(auto it = arrays.begin(); it != arrays.end(); it++)
    {
        if (arrays.size() == 0)
            cout << "No subarray exists";
        else
            cout << " { " << it->first << " , " << it->second << " } " << endl;
    }
}
