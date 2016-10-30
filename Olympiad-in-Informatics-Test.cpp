// Olympiad-in-Informatics-Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int card[20];
int n;
int ans = 0xfffffff, temp_ans = 0;
enum CardType
{
	n3, n4, n5, n6, nn7, n8, n9, n10, J, Q, K, A, n2, GS, GB
};
typedef  CardType ct;
void init(int n) {
	int t1, t2;
	for (int i = 1; i <= n; i++) {
		cin >> t1 >> t2;
		if (t1 >= 3 && t1 <= 13)card[t1 - 3]++;
		else if (t1 == 1 || t1 == 2)card[t1 + 10]++;
		else if (t1 == 0 && t2 == 1)card[ct::GS]++;
		else if (t1 == 0 && t2 == 2)card[ct::GB]++;
	}

	if (card[ct::GB] && !card[ct::GS] || !card[ct::GB] && card[ct::GS]) {
		card[ct::GB] = card[ct::GS] = 0;
		temp_ans++;
	}
	if (card[ct::GB] && card[ct::GS]) { card[ct::GB] = card[ct::GS] = 0; temp_ans += 1; }
	//��С��ǿ�Ƶ���
}

bool isFinished() {
	for (int i = ct::n3; i <= ct::GB; i++) if (card[i])return false;
	return true;
}
bool dfs(int times) {
	if (ans < times) return false;
	if (isFinished()) { ans = times; return true; }
	for (int i = ct::n3; i <= ct::K - 4; i++) {
		bool b = false;
		if (card[i] && card[i + 1] && card[i + 2] && card[i + 3] && card[i + 4]) {
			for (int j = i; j <= i + 4; j++)card[j]--;
			dfs(times + 1);
			for (int j = i; j <= i + 4; j++)card[j]++;
			for (int j = i + 5; j <= ct::K - 4 && j - i >= 5; j++) {
				if (card[j]) {
					for (int k = i; k <= j; k++)card[j]--;
					dfs(times + 1);
					for (int k = i; k <= j; k++)card[j]++;
				}
				else
					break;
			}
		}
	}//��˳��

	for (int i = 1; i <= 15 - 2 - 2 - 2; i++) {
		if (card[i] >= 2 && card[i + 1] >= 2 && card[i + 2] >= 2) {
			for (int j = i; j <= i + 2; j++)card[j] -= 2;
			dfs(times + 1);
			for (int j = i; j <= i + 2; j++)card[j] += 2;
			for (int j = i + 3; j <= 15 - 2 - 2 && j - i >= 3; j++) {
				if (card[j] >= 2) {
					for (int k = i; k <= j; k++)card[k] -= 2;
					dfs(times + 1);
					for (int k = i; k <= j; k++)card[k] += 2;
				}
				else break;
			}
		}
	}//˫˳��

	for (int i = 1; i <= 15 - 2 - 2 - 1; i++) {
		if (card[i] >= 3 && card[i + 1] >= 3) {
			for (int j = i; j <= i + 1; j++)card[j] -= 3;
			dfs(times + 1);
			for (int j = i; j <= i + 1; j++)card[j] += 3;
			for (int j = i + 2; j <= 15 - 2 - 2 && j - i >= 2; j++) {
				if (card[j] >= 3) {
					for (int k = i; k <= j; k++)card[k] -= 3;
					dfs(times + 1);
					for (int k = i; k <= j; k++)card[k] += 3;
				}
				else break;
			}
		}
	}//��˳��

	for (int i = ct::n3; i <= ct::n2; i++) {
		if (card[i] >= 3) {
			for (int j = ct::n3; j <= ct::GB; j++) {
				if (i != j&&card[j]) {
					card[i] -= 3; card[j]--;
					dfs(times + 1);
					card[i] += 3; card[j]++;
				}
			}
		}
	}//����һ


	for (int i = ct::n3; i <= ct::n2; i++) {
		if (card[i] >= 3) {
			for (int j = ct::n3; j <= ct::n2; j++) {
				if (i != j&&card[j] >= 2) {
					card[i] -= 3; card[j] -= 2;
					dfs(times + 1);
					card[i] += 3; card[j] += 2;
				}
			}
		}
	}//������

	for (int i = ct::n3; i <= ct::n2; i++) {
		if (card[i] >= 4) {
			card[i] -= 4;
			for (int j = ct::n3; j <= ct::n2; j++)
				if (i != j&&card[j] >= 2)
					for (int k = ct::n3; k <= ct::n2; k++)
						if (k != i&&k != j&&card[k] >= 2) {
							card[k] -= 2; card[j] -= 2;
							dfs(times + 1);
							card[k] += 2; card[j] += 2;
						}//�Ĵ��������ԣ�
			for (int j = ct::n3; j <= ct::GB; j++) 
				if (i != j&&card[j])
					for(int k = ct::n3;k<=ct::GB;k++)
						if (k != i&&k != j&&card[k]) {
							card[k]--; card[j]--;
							dfs(times + 1);
							card[k]++; card[j]++;
						}//�Ĵ�����������
		}
	}
	//for (int i = 1; i <= 15 - 2 - 2; i++) {
	//	if (card[i] == 4) {
	//		card[i] -= 4;
	//		dfs(times + 1);
	//		card[i] += 4;
	//	}
	//}//ը��



}

int main() {
	std::ios_base::sync_with_stdio(false);
	int t; cin >> t >> n;
	while (t--) { init(n); dfs(0); }
	system("pause");
	return 0;
}