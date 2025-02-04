#pragma once
#include"defult.h"
#include<chrono>


#ifdef RUN_SOLUTION343

using namespace std;

int integerBreak(int n) {
	if (n == 2) return 1;
	if (n == 3) return 2;
	int result = 1;
	while (n > 4) {
		result *= 3;
		n -= 3;
	}
	return result * n;

}
//2 <= n <= 58
int integerBreak2(int n) {
	auto result = vector(n + 1, 0);
	result[2] = 1;
	for (auto i{ 3 }; i <= n; i++) {
		for (auto j{ 1 }; j < (i/2)+1; j++) {
			result[i] = max(result[i], max(j * (i - j), j * result[i - j]));
		}
	}
	return result[n];
}


int main() {
	auto start = std::chrono::system_clock::now();
	std::println("{}", integerBreak2(100)); // Output: 1
	auto end1 = std::chrono::system_clock::now();
	std::println("{}", integerBreak2(100)); // Output: 36
	auto end2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed1 = end1 - start;
	std::chrono::duration<double> elapsed2 = end2 - end1;
	std::println("Elapsed time1:{} ", elapsed1.count());
	std::println("Elapsed time2:{} ", elapsed2.count());
}
#endif 