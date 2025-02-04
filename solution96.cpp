#include"defult.h"

#ifdef RUN_SOLUTION96
using namespace std;

int numTrees(int n) {
	auto result = vector(n + 1, 0);
	result[0] = 1;
	result[1] = 1;
	for (auto i{ 2 }; i <= n; i++) {
		for (auto j{ 1 }; j <= i; j++) {
			result[i] += result[j - 1] * result[i - j];
		}
	}
	return result[n];
}

int main() {
	std::println("{}", numTrees(3)); // Output: 5
	std::println("{}", numTrees(1)); // Output: 1
	std::println("{}", numTrees(2)); // Output: 2
}



#endif