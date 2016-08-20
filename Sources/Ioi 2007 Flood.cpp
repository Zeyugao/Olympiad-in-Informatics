/*ÿ�Σ��������µ�һ���㿪ʼ�������һ������Χ���������������ߣ�ֱ���ص���㡣
����һ�����Եõ�һ��Ȧ�������Ȧ�ϳ���2�εıߣ�����Ҫ����ıߡ�
�Ͱ����Ƥһ����һ��һ���ɾȦ��

��ʵ����ı�û�б�Ҫ��������ƽ�У����������Ի��ԣ����´����ͼ���㷨�����鼯, BFS�ȣ���
��Ϊ���ⲻ��Ҫ�������Сʱ�������ǽ���Ͳ��������·��
*/

#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_N = 100000;

int n, m;
pair<int, int> p[MAX_N];
pair<int, int> graph[MAX_N][4];
int order[MAX_N];
int stamp[MAX_N * 2];
int curStamp;

bool walk(int s)
{
	curStamp++;
	int d = stamp[graph[s][0].second] >= curStamp ? 0 :
	stamp[graph[s][1].second] >= curStamp ? 1 : -1;
	if (d == -1) return false;
	for (int i = s; d += 3; d %= 4)
	{
		while (stamp[graph[i][d % 4].second] < curStamp) d++;
		stamp[graph[i][d % 4].second] =
		stamp[graph[i][d % 4].second] == curStamp ? -1 : curStamp;
		i = graph[i][d % 4].first;
		if (i == s) break;
	}
	return true;
}
bool lessThan(int i, int j)
{
	return p[i] < p[j];
}
int getDirection(int i, int j)
{
	return (p[i] > p[j]) * 2 + (p[i].first == p[j].first);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &p[i].first, &p[i].second);
		order[i] = i;
	}
	sort(order, order + n, lessThan);
	memset(graph, 0, sizeof(graph));
	scanf("%d", &m);
	for (int k = 1; k <= m; k++)
	{
		int i, j;
		scanf("%d%d", &i, &j);
		i--, j--;
		graph[i][getDirection(i, j)] = make_pair(j, k);
		graph[j][getDirection(j, i)] = make_pair(i, k);
	}

	memset(stamp, 1, sizeof(stamp));
	stamp[0] = -1;
	curStamp = 0;
	for (int i = 0; i < n; i++)
	while (walk(order[i]));

	printf("%d\n", count(stamp + 1, stamp + m + 1, -1));
	for (int k = 1; k <= m; k++)
		if (stamp[k] == -1)
	printf("%d\n", k);
	return 0;
}
