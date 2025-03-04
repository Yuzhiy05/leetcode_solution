#pragma once
#include"defult.h"

#ifdef RUN_SOLUTION238
using namespace std;
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result_prefix(nums.size(), 1);
        vector<int> result_suffix(nums.size(), 1);
        for (const auto [i, _] : views::enumerate(nums) | views::drop(1)) {
            result_prefix[i] = result_prefix[i - 1] * nums[i - 1];
        }
        auto reverse_v = nums | views::reverse;
        for (const auto [i, _] :
            reverse_v | views::enumerate | views::drop(1)) {
            result_suffix[i] = result_suffix[i - 1] * reverse_v[i - 1];
        }
        auto result = ::views::zip_transform(std::multiplies{}, result_prefix,
            result_suffix | views::reverse);
        return ranges::to<vector>(result);
    }
	int main() {
		vector<int> nums{ 1,2,3,4 };
		std::println("{}", productExceptSelf(nums)); // Output: 24,12,8,6
	}

  
#endif