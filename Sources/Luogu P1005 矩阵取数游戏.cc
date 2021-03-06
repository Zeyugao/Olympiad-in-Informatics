#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXNUM 10000
#define LEN 4

//高精度奇奇怪怪的

//原先用引用就全部complie error
class BigNum {
  public:
	int num_array[100];
	int len;
	BigNum() { memset(num_array, 0, sizeof(num_array)); len = 1; }
	BigNum(int);
	BigNum operator=(int);
	BigNum &operator=(BigNum);
	BigNum operator+(const BigNum)const;
	BigNum operator*(const BigNum)const;
	bool operator<(const BigNum)const;
	friend ostream &operator<<(ostream &, const BigNum &);
};


//struct BigNum {
//    int num_array[100];
//    int len;
//    BigNum() { memset(num_array, 0, sizeof(num_array)); len = 1; }
//    BigNum operator=(int b)
//    {
//        memset(num_array, 0, sizeof(num_array));
//        len = 1;
//        while (b > MAXNUM) {
//            num_array[len++] = b%MAXNUM;
//            b /= MAXNUM;
//        }
//        if (b == 0) {
//            len--;
//        }
//        else {
//            num_array[len] = b;
//        }
//        return *this;
//    }
//    BigNum operator=(BigNum a)
//    {
//        len = a.len;
//        for (int i = 1; i <= len; i++) {
//            num_array[i] = a.num_array[i];
//        }
//        return *this;
//    }
//    BigNum operator+(const BigNum b) const
//    {
//        BigNum c;
//        c.len = max(len, b.len);
//        for (int i = 1; i <= c.len; i++) {
//            c.num_array[i] += num_array[i] + b.num_array[i];
//            c.num_array[i + 1] += c.num_array[i] / MAXNUM;
//            c.num_array[i] %= MAXNUM;
//        }
//        if (c.num_array[c.len + 1]) {
//            c.len++;
//        }
//        return c;
//    }
//    BigNum operator*(const int b) const
//    {
//        BigNum c;
//        c.len = len+1;
//        for (int i = 1; i <= len; i++) {
//                c.num_array[i] += num_array[i] * b;
//                c.num_array[i + 1] += c.num_array[i] / MAXNUM;
//                c.num_array[i] %= MAXNUM;
//        }
//        while (c.num_array[c.len] == 0)c.len--;
//        return c;
//    }
//
//    bool operator<(const BigNum b) const
//    {
//        if (len != b.len)return len < b.len;
//        for (int i = len; i >= 1; i--) {
//            if (num_array[i] != b.num_array[i]) {
//                return num_array[i] < b.num_array[i];
//            }
//        }
//
//        //即使相等也算小于不成立
//        return false;
//    }
//};
//void out(const BigNum a)
//{
//    cout << a.num_array[a.len];
//    for (int i = a.len - 1; i >= 1; i--) {
//        cout.width(LEN);
//        cout.fill('0');
//        cout << a.num_array[i];
//    }
//}
BigNum::BigNum(int num) {
	memset(num_array, 0, sizeof(num_array));
	len = 1;
	while (num > MAXNUM) {
		num_array[len++] = num % MAXNUM;
		num /= MAXNUM;
	}
	if (num == 0) {
		len--;
	}
	else {
		num_array[len] = num;
	}
}
BigNum BigNum::operator*(const BigNum b) const {
	BigNum c;
	c.len = len + b.len;
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= b.len; j++) {
			c.num_array[i + j - 1] += num_array[i] * b.num_array[j];
			c.num_array[i + j] += c.num_array[i + j - 1] / MAXNUM;
			c.num_array[i + j - 1] %= MAXNUM;
		}
	}
	while (c.num_array[c.len] == 0) { c.len--; }
	return c;
}
BigNum BigNum::operator=(int b) {
	memset(num_array, 0, sizeof(num_array));
	len = 1;
	while (b > MAXNUM) {
		num_array[len++] = b % MAXNUM;
		b /= MAXNUM;
	}
	if (b == 0) {
		len--;
	}
	else {
		num_array[len] = b;
	}
	return *this;
}
BigNum &BigNum::operator=(BigNum a) {
	len = a.len;
	for (int i = 1; i <= len; i++) {
		num_array[i] = a.num_array[i];
	}
	return *this;
}
BigNum BigNum::operator+(const BigNum b) const {
	BigNum c;
	c.len = max(len, b.len);
	for (int i = 1; i <= c.len; i++) {
		c.num_array[i] += num_array[i] + b.num_array[i];
		c.num_array[i + 1] += c.num_array[i] / MAXNUM;
		c.num_array[i] %= MAXNUM;
	}
	if (c.num_array[c.len + 1]) {
		c.len++;
	}
	return c;
}

ostream &operator<<(ostream &out, const BigNum &a) {
	out << a.num_array[a.len];
	for (int i = a.len - 1; i >= 1; i--) {
		out.width(LEN);
		out.fill('0');
		out << a.num_array[i];
	}
	return out;
}
bool BigNum::operator<(const BigNum b) const {
	if (len != b.len) { return len < b.len; }
	for (int i = len; i >= 1; i--) {
		if (num_array[i] != b.num_array[i]) {
			return num_array[i] < b.num_array[i];
		}
	}
	
	//即使相等也算小于不成立
	return false;
}
/*
Summary:
    dp[i][j]代表左取到i，右取到j，i=0时，左边不取，j=m+1时，右边不取
    dp[i][j] =max(dp[i-1][j]+num[i]*2^(取到第几个),dp[i][j+1]+num[j]*2^(取到第几个))
    其中i,j∈[0,m+1] and i<j
    2** 需要预处理
*/

int m;
//二的m次方预处理
BigNum two_power[81];
//long two_power[81] = { 0 };
void calc_power() {
	two_power[0] = 1;
	
	for (int i = 1; i <= m; i++) {
		two_power[i] = two_power[i - 1] * 2;
	}
}

inline BigNum get_max_ans(BigNum(*dp)[81]) {
	BigNum ans;
	for (int i = 0; i <= m; i++) {
		if (ans < dp[i][i + 1]) { ans = dp[i][i + 1]; }
	}
	return ans;
}
inline int pos(int i, int j) { return i + (m + 1 - j); }
int main() {

	int n;
	BigNum ans;
	//long ans = 0;
	cin >> n >> m;
	calc_power();
	while (n--) {
		int num[81] = { 0 };
		BigNum dp[81][81];
		//long dp[81][81] = { 0 };
		for (int i = 1; i <= m; i++) {
			cin >> num[i];
		}
		for (int i = 0; i <= m; i++) {
		
			for (int j = m + 1; j > i; j--) {
				dp[i][j] = 0;
				if (i != 0) {
					dp[i][j] = dp[i - 1][j] + two_power[pos(i, j)] * num[i];
				}
				if (j != m + 1) {
					BigNum tmp = dp[i][j + 1] + two_power[pos(i, j)] * num[j];
					//long  tmp = dp[i][j + 1] + two_power[calc(i, j)] * num[j];
					if (dp[i][j] < tmp) {
						dp[i][j] = tmp;
					}
				}
			}
		}
		ans = ans + get_max_ans(dp);
	}
	//out(ans);
	cout << ans << endl;
	return 0;
}