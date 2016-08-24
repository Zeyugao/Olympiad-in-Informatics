/*��������ζ�̬�滮�⣬�漰���˺���֮��ķ������⣬��Ҫ�ú����ֵܱ�ʾ����ʵ�֡�

���ȣ��ж��н��������M-1<=N-K������2<=M<=N����M=2ʱ���൱�ڰ����нڵ�Ⱦ�ϲ�ͬ��ɫ��������ɫ�� ͬ�ı�Ҫ������Ȩֵ����Ȩֵ��С�ķ������ٶ�����ͷ��Ҫ�ԵĽڵ�Ϊ��ɫ�ڵ㣬����Ϊ��ɫ�ڵ㡣������Ҫ�������е�������ɫ��ͬ�ıߡ����M>2���� ֻ��Ҫ�������˶��Ǻ�ɫ�ıߡ���Ϊ��ʣ����ɫ����1ʱ��һ�������ҵ�һ�ַ�����ʹ�á�Сͷ������������֦��

����i.sonΪi�ĵ�һ�����ӣ�i.brotherΪi���ֵܽڵ㣬i.costΪi���丸�����ӵıߵ�Ȩֵ��

״̬����

F[i][j][k]Ϊ��iΪ���������������ұߵ��ֵ�Ϊ���������У���j���ڵ㱻Ⱦ�ڣ���i�ĸ��׽ڵ����ɫΪk(1Ϊ��ɫ��0Ϊ����)ʱ����С����

״̬ת�Ʒ���

F[i][j][k]=Min
{
    F[i.son][j'][0] + F[i.brother][j-j'][k] + D(0,k)  i.cost,
    F[i.son][j'][1] + F[i.brother][j-j'-1][k] + D(1,k)  i.cost,
}
���� D(a,b)��ʾ������ɫΪa,b֮��ı��Ƿ�Ҫ���Ե������嶨��Ϊ
D(a,b) = 
{
    1 | a=b=1
    1 | a=b=0 �� M=2
    0 | �������
}
�߽�����
�ڵ�0��ʾһ������Ŀսڵ�

F[0][0][k] = 0 (k=0,1)

F[0][j][k] = ����� (j>0 k=0,1)

Ŀ��״̬

F[�ڵ�1.son][K-1][1]

 * Problem: NOI2002 dragon
 * Author: Guo Jiabao
 * Time: 2009.5.18 14:02
 * State: Solved
 * Memo: ���ζ�̬�滮 �����ֵܷ�������
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
const int MAXN=301,INF=0x7FFFFFF;
using namespace std;
struct edge
{
    edge *next;
    int t,c;
}*V[MAXN],ES[MAXN*2];
struct node
{
    int son,brother,cost;
}T[MAXN];
int N,M,K,EC,Ans,Stack[MAXN];
bool vis[MAXN];
int F[MAXN][MAXN][2];
inline void addedge(int a,int b,int c)
{
    ES[++EC].next = V[a];
    V[a]=ES+EC; V[a]->t=b; V[a]->c=c;
    ES[++EC].next = V[b];
    V[b]=ES+EC; V[b]->t=a; V[b]->c=c;
}
void maketree()
{
    int i,j,Stop;
    Stack[Stop=1]=1;
    while (Stop)
    {
        i=Stack[Stop--];
        vis[i]=true;
        for (edge *e=V[i];e;e=e->next)
        {
            j=e->t;
            if (!vis[j])
            {
                T[j].brother=T[i].son;
                T[j].cost=e->c;
                T[i].son=j;
                Stack[++Stop]=j;
            }
        }
    }
}
void init()
{
    int i,a,b,c;
    freopen("dragon.in","r",stdin);
    freopen("dragon.out","w",stdout);
    scanf("%d%d%d",&N,&M,&K);
    for (i=1;i<N;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b,c);
    }
    maketree();
    memset(F,-1,sizeof(F));
}
inline int D(int a,int b)
{
    return ((a==1 && b==1)||(a==0 && b==0 && M==2));
}
int DP(int i,int j,int k)
{
    if (F[i][j][k]==-1)
    {
        int a,v,rs=INF;
        for (a=0;a<=j;a++)
        {
            v = DP(T[i].son,a,0) + DP(T[i].brother,j-a,k) + D(0,k) * T[i].cost;
            if (v<rs) rs=v;
            if (a<j)
            {
                v = DP(T[i].son,a,1) + DP(T[i].brother,j-a-1,k) + D(1,k) * T[i].cost;
                if (v<rs) rs=v;
            }
        }
        F[i][j][k]=rs;

    }
    return F[i][j][k];
}
void solve()
{
    if (M-1 <= N-K)
    {
        F[0][0][0]=F[0][0][1]=0;
        for (int i=1;i<=K;i++)
            F[0][i][0]=F[0][i][1]=INF;
        Ans=DP(T[1].son,K-1,1);
    }
    else
        Ans=-1;
}
int main()
{
    init();
    solve();
    printf("%d\n",Ans);
    return 0;
}
