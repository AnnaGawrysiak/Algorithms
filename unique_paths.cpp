#include <iostream>
#include <vector>
#include <iomanip>

int unique_paths(int m, int n);
void print_2D_vec(const std::vector<std::vector<int>>& vec);

int main()
{
	const int nr_of_rows = 3;
	const int nr_of_cols = 7;

	std::cout << "Nr of paths: " << unique_paths(nr_of_rows, nr_of_cols) << std::endl;

	return 0;
}

int unique_paths(const int m, const int n)
{
	if (m == 0 && n == 0)
		return 0;

	std::vector < std::vector<int>> dp(m, std::vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i < dp.size(); i++)
	{
		for (int j = 1; j < dp[i].size(); j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1];

		std::cout << std::endl;
	}

	//print_2D_vec(dp);

	return dp[m-1][n-1];

}

void print_2D_vec(const std::vector<std::vector<int>>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
			std::cout << std::setw(8) << vec[i][j] << " ";

		std::cout << std::endl;
	}
}