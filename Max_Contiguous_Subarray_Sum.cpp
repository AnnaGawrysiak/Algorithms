/*
Given an array with integers, return the sum of the subarray with the largest sum.

A "subarray" is a subset of the original array that is contiguous and maintains the sequence of all elements from the original array.

Example:
Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: The maximum sum subarray goes from index 3 to index 6 with a total sum of 6.

*/
#include <iostream>
#include <vector>
#include <tuple>

std::tuple<int, int, int>  maxContiguousSubarraySum(std::vector<int>& nums);

int main()
{
    std::vector<int> my_vector = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    auto [index_start, index_end, sum] = maxContiguousSubarraySum(my_vector);

    std::cout << "The maximum sum subarray goes from index " << index_start << " to index " << index_end << " with a total sum of " << sum << " ." << std::endl;

    return 0;
}

std::tuple<int, int, int> maxContiguousSubarraySum(std::vector<int>& nums)
{
    int sum = nums[0];
    int end = 0;
    int best = sum;

    for (int i = 1; i < nums.size(); i++)
    {
        sum = std::max(sum + nums[i], nums[i]);
        if (sum > best)
            end = i;
        best = std::max(sum, best);
    }

    int start = end;
    int printed_sum = nums[start];

    while (printed_sum < best)
    {
        start--;
        printed_sum += nums[start];

    }


    return { start, end, best };
}