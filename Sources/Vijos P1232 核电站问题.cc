#include <iostream>
#include <string.h>
using namespace std;


int main() {
	long long dp[60] = {0};
	
	dp[0] = 1;
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	
	
		if (i < m) {
			dp[i] = 2 * dp[i - 1];
			//小于m个时，不需要考虑会不会有连续的，每添加一个坑，都会有放or不放的选择，直接*2即可
		}
		else if (i == m) {
			dp[i] = 2 * dp[i - 1] - 1;
			//最后一个不能放了，只能有一种情况
		}
		else {
			dp[i] = 2 * dp[i - 1] - dp[i - m - 1];
			//这里-dp[i-m-1]是为了减去在i前m个全都有的情况，而i前m个全都有的情况的方案总数为f[i-m-1]，（f[i-m]是通过2*f[i-m-1]的到得，由两种情况，第i-m个有核弹的情况为其一半，也就是f[i-m-1]个
		}
	}
	cout << dp[n] << endl;
	
	
	return 0;
}
