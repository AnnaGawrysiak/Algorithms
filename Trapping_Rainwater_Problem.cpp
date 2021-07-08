// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.
// Example: 
//Input: height = [4,2,0,3,2,5]
// Output: 9
#include <iostream>
#include <vector>

float trapped_water(const std::vector<int>& levels);

int main()
{
	std::vector<int> heights = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	std::cout << trapped_water(heights) << std::endl;
   return 0;
}

float trapped_water(const std::vector<int>& levels)
{
	if (levels.size() < 3)
		return 0;

	int max_right = 0;
	int max_left = 0;

	int right = levels.size() - 1;
	int left = 0;

	int water = 0;

	while (left < right)
	{
		if (levels.at(left) < levels.at(right))
		{
			std::cout << "levels.at(left)" << levels.at(left) << std::endl;
			std::cout << "max_left" << max_left << std::endl;
			std::cout << std::endl;
			levels.at(left) >= max_left ? max_left = levels.at(left) : water += (max_left - levels.at(left));
			left++;

		}
		else
		{
			levels.at(right) >= max_right ? max_right = levels.at(right) : water += (max_right - levels.at(right));
			right--;
		}
		
	}

	return water;
}