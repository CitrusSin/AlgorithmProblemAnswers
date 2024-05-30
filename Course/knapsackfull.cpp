#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

int main() {
	size_t n;
	std::cout << "请输入物品总量：";
	std::cin >> n;
	
	std::vector<uint64_t> weight(n), value(n);
	std::cout << "请按序输入物品1到物品" << n << "的重量：";
	for (int i=0; i<n; i++) std::cin >> weight[i];
	std::cout << "请按序输入物品1到物品" << n << "的价值：";
	for (int i=0; i<n; i++) std::cin >> value[i];

	uint64_t m;
	std::cout << "请输入背包最大载重：";
	std::cin >> m;

	std::vector<std::vector<uint64_t>> dp(n+1, std::vector<uint64_t>(m+1, 0));
	
	// 计算动态规划表
	for (size_t i=0; i<n; i++) {
		for (size_t j=0; j<=m; j++) {
			dp[i+1][j] = dp[i][j];
			//if (j >= weight[i] && dp[i+1][j] < dp[i][j-weight[i]] + value[i]) {
			if (j >= weight[i] && dp[i+1][j] < dp[i+1][j-weight[i]] + value[i]) {
				dp[i+1][j] = dp[i+1][j-weight[i]] + value[i];
			}
		}
	}

	// 根据动态规划表回溯最优解
	std::vector<uint64_t> selection;
	uint64_t m2 = m;
	for (uint64_t idx = n; idx > 0;) {
		if (weight[idx-1] <= m2 && dp[idx][m2-weight[idx-1]] + value[idx-1] > dp[idx-1][m2]) {
			selection.push_back(idx);
			m2 -= weight[idx-1];
		} else {
			idx--;
		}
	}
	std::reverse(selection.begin(), selection.end());
	int64_t used_weight = m - m2;

	// 结果输出
	std::cout << std::endl;
	std::cout << "-------------------计算结果--------------------" << std::endl;
	std::cout << "能获得的最大价值：" << dp[n][m] << std::endl;
	std::cout << "此时应选择这些物品编号：";
	for (uint64_t item : selection) {
		std::cout << item << ' ';
	}
	std::cout << std::endl;
	std::cout << "此时载重：" << used_weight << std::endl;

	std::cout << std::endl << "动态规划计算表：" << std::endl;
	for (uint64_t j=0; j<=m; j++) {
		std::cout << '\t' << j;
	}
	std::cout << std::endl;
	for (size_t i=0; i<=n; i++) {
		std::cout << i;
		for (uint64_t j=0; j<=m; j++) {
			std::cout << '\t' << dp[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}
