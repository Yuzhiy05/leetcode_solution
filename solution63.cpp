#pragma once
#include"defult.h"
#include<mdspan>

#ifdef RUN_SOLUTION63

using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	auto m = obstacleGrid.size();
	auto n= obstacleGrid[0].size();
	auto result=vector<vector<int>>(m,vector<int>(n,0));
	for (auto i{0}; i < m&&obstacleGrid[i][0]==0; i++) 
		result[i][0] = 1;
	for (auto i{0};i< n&&obstacleGrid[0][i]==0; i++) 
		result[0][i] = 1;

	for (auto i{1}; i < m; i++) {
		for(auto j{1}; j < n; j++) {
			if (obstacleGrid[i][j] == 0) {
				result[i][j] = result[i - 1][j] + result[i][j - 1];
			}
		}
	}
	return result[m-1][n-1];
}
int unqiuePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
	auto result = vector(obstacleGrid.size() * obstacleGrid[0].size(), 0);
	auto dpspan = mdspan(result.data(), obstacleGrid.size(), obstacleGrid[0].size());
	for (auto i{ 0 }; i < dpspan.extent(0) && obstacleGrid[i][0] == 0; i++)
		dpspan[array{ i,0 }] = 1;
	for (auto i{ 0 }; i < dpspan.extent(1) && obstacleGrid[0][i] == 0; i++)
		dpspan[array{ 0,i }] = 1;

	for (auto i{ 1 }; i < dpspan.extent(0); i++) {
		for (auto j{ 1 }; j < dpspan.extent(1); j++) {
			if (obstacleGrid[i][j] == 0) {
				dpspan[array{ i, j }] = dpspan[array{ i - 1, j }] + dpspan[array{ i, j - 1 }];
			}
		}
	}
	return dpspan[dpspan.extent(0) - 1,dpspan.extent(1) - 1];
	
}

int main() {
	vector<vector<int>> obstacleGrid{ {0,0,0},{0,1,0},{0,0,0} };
	std::println("{}", unqiuePathsWithObstacles2(obstacleGrid)); // Output: 2
}

#endif