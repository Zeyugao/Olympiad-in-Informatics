/*���͵�˫��Spfa���� 
���ţ�������˵ĵط����룬�����ĵط������� 
��˵�һ������Spfa�ҵ��۸���͵ĵص㣬���ڸô����룻�ڶ��鷴��Spfa�ҵ��۸���ߵĵص㣬��Ϊ�����㡣 
ans=max{max_cost[i]-min_cost[i]};*/



//����ͨ��spfa��n->i��˵����һ���ܴ�i��i~n�����ֵ�У�
//��1->i,˵��Ҳ�ܴ�1�ߵ�i~n����Сֵ�����ܹ������ߵ�i 
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int a[100001],Max[100001],Min[100001];
int q[1000001],h,t;
bool v[100001];
vector<int> edge[100001],edge1[100001];
int main()
{
    //freopen("trade.in","r",stdin);
    //freopen("trade.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i =1;i <= n;i ++) scanf("%d",&a[i]);
    for (int i = 1;i <= m;i ++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edge[x].push_back(y);
        if (z > 1) edge[y].push_back(x);
        edge1[y].push_back(x);
        if (z > 1) edge1[x].push_back(y);
    }
    memset(Min,63,sizeof(Min));
    Min[1] = a[1];
    q[1] = 1;
    v[1] = true;
    h = 0,t = 1;
    while (h < t)
    {
        if (h != 0) v[q[h]] = false;
        h ++;
        for (int i = 0;i < edge[q[h]].size();i++)
            if (Min[edge[q[h]][i]] > min(a[edge[q[h]][i]],Min[q[h]]))
            {
                Min[edge[q[h]][i]] = min(a[edge[q[h]][i]],Min[q[h]]);
                if (!v[edge[q[h]][i]]) 
                {
                    q[++t] = edge[q[h]][i];
                    v[edge[q[h]][i]] = true;
                }
            }
    }
    memset(v,0,sizeof(v));
    Max[n] = a[n];
    q[1] = n;
    v[n] = true;
    h = 0,t = 1;
    while (h < t)
    {
        if (h != 0) v[q[h]] = false;
        h ++;
        for (int i = 0;i < edge1[q[h]].size();i++)
            if (Max[edge1[q[h]][i]] < max(a[edge1[q[h]][i]],Max[q[h]]))
            {
                Max[edge1[q[h]][i]] = max(a[edge1[q[h]][i]],Max[q[h]]);
                if (!v[edge1[q[h]][i]]) 
                {
                    q[++t] = edge1[q[h]][i];
                    v[edge1[q[h]][i]] = true;
                }
            }
    }
    int ans = 0;
    for (int i = 1;i <= n;i ++)
    {
        //printf("%d %d\n",Max[i],Min[i]);
        ans = max(ans,Max[i] - Min[i]);
    }
    cout << ans;
}
