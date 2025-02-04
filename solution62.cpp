#pragma once
#include"defult.h"
#include<mdspan>
#include<chrono>

/*
 62. 不同路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
输入：m = 3, n = 7
输出：28
示例 2：

输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
示例 3：

输入：m = 7, n = 3
输出：28
示例 4：

输入：m = 3, n = 3
输出：6
*/
#ifdef RUN_SOLUTION62

 int uniquePaths(int m, int n) {
	std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		dp[i][0] = 1;
	}
	for (int i = 0; i < n; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

 int main() {
	auto start = std::chrono::system_clock::now(); 
	std::println("{}", uniquePaths(3, 7)); // Output: 28
	std::println("{}", uniquePaths(3, 2)); // Output: 3
	std::println("{}", uniquePaths(7, 3)); // Output: 28
	std::println("{}", uniquePaths(3, 3)); // Output: 6
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::println("Elapsed time:{} ",elapsed.count());
}
#endif

