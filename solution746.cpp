#pragma once
#include"defult.h"


#ifdef RUN_SOLUTION746

int minCostClimbingStairs(std::vector<int>& cost) {
	std::vector<int> dp(cost.size());
	dp[0] = cost[0];
	dp[1] = cost[1];
	for (int i = 2; i < cost.size(); i++) {
		dp[i] = cost[i] + std::min(dp[i-1], dp[i-2]);
	}
	return std::min(dp[cost.size()-1], dp[cost.size()-2]);
}
int minCostClimbingStairs2(std::vector<int>& cost) {
	std::vector<int> result(cost.size());
	for (const auto& [index, x] : std::views::enumerate(cost))
	{
		if (index < 2) {
			result[index] = cost[index];
		}
		else {
			result[index] = cost[index]+std::ranges::min(result[index - 1], result[index - 2]);
		}
	}
	return std::min(*(result.end() - 1), *(result.end() - 2));
}



 int main() {
	std::vector<int> cost{10, 15, 20};
	std::println("{}",minCostClimbingStairs2(cost)); // Output: 15
	cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	std::println("{}", minCostClimbingStairs2(cost)); // Output: 6
}
#endif