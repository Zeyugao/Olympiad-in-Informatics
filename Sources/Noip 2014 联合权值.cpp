/*
�����Ŀ�Ĺؼ�������������ͼ��ʵ����һ����
��ô��ͬһ�����׽ڵ��������ӽڵ�֮��ľ���ض���2
Ȼ��ÿ����ŵĽڵ㶼���Կ������׽ڵ㣬�ӽڵ�Ϳ������ڽӱ�洢�ˣ����ص��ı��ڴ�
Ȼ�����������Ȩֵ��ʵ������һ�����׽ڵ����������ӽڵ��������͵ڶ����ȨֵȻ����ܲ����������Ȩֵ
������Ȩֵ=��ÿ�����׽ڵ��������Ȩֵ
��ÿ�����׽ڵ��������Ȩֵ=W10+W1W2+(W1+W2)W3+(W1+W2+W3)W4+...+(W1+...+Wn-1)Wn
�����ڱ��������ӽڵ��ʱ�򣬿���һ�������͵ڶ����Ȩֵ��һ������������Ȩֵ���߼ӱ�ȡ���Է���int
W_total+=((��W1+...Wn-1)%10007)Wn*2%10007
������Ҫ����ÿ�����׽ڵ㣬���������������ӽڵ㣬���ڱ���=�ڵ���-1������Ӧ�ñȽϿ��
*/ 

include<cstdio>
int n,path[400001][2],index[200001],w[200001];
int main()
{
int i,j,a,b,k,sum,max_1,max_2,max_t=0,w_t=0;
freopen("link10.in","r",stdin);
scanf("%d",&n);
for(i=1;i<n*2-1;i+=2)
{
    scanf("%d%d",&a,&b);    //���ڽӱ��������ͼ (������ʵ������ 

    path[i][0]=b;
    path[i][1]=index[a];
    index[a]=i;

    path[i+1][0]=a;
    path[i+1][1]=index[b];
    index[b]=i+1;
}

for(i=1;i<=n;i++)    scanf("%d",&w[i]);    //����ÿ�����Ȩֵ 

for(i=1;i<=n;i++)                        //��ʼ����ÿ�����׽ڵ� 
{
    a=index[i];                            //��ʼ�� 
    sum=0;        //�ӽڵ�Ȩֵ�ۼ� 
    max_1=0;    //�ӽڵ�������Ȩֵ 
    max_2=0;    //�ӽڵ��еڶ����Ȩֵ 

	while(path[a][0])                    //������ÿ�����׽ڵ������������ӽڵ� 
	{    
		b=w[path[a][0]];                //��ȡ��ǰ�ӽڵ��Ȩֵ 

		if(b>max_1)    max_1 = b;                    //�����ӽڵ����͵ڶ����Ȩֵ 
		else         max_2 = max_2>b ? max_2:b;

		w_t+=(sum%10007)*b*2%10007;        //Sum���Ե�ǰ�ӽڵ�Ȩֵ�ٳ�2��ȡ��10007 
		w_t%=10007;        
		sum+=b;                            //��֮ǰ�������ӽڵ�Ȩֵ�����ۼ���� 

		a=path[a][1];                    //��ת����һ���ӽڵ� 
	}

    k=max_1*max_2;                        //�õ���ǰ���׽ڵ���������Ȩֵ���Ƚ�ȫ���������Ȩֵ 
    	max_t=max_t>k ? max_t:k;
	}

	printf("%d %d",max_t,w_t);                //������ 
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
 
using namespace std;
 
const int maxn = 200009;
const int MOD = 10007;
 
int N, w[maxn], mx[maxn], cnt[maxn], ans = 0, tot = 0;
 
inline int read() {
    char c = getchar();
    int ret = 0;
    for(; !isdigit(c); c = getchar());
    for(; isdigit(c); c = getchar())
        ret = ret * 10 + c - '0';
    return ret;
}
 
struct edge {
    int to;
    edge* next;
} E[maxn << 1], *pt = E, *head[maxn];
 
inline void add(int u, int v) {
    pt->to = v; pt->next = head[u]; head[u] = pt++;
}
inline void addedge(int u, int v) {
    add(u, v); add(v, u);
}
 
void init() {
    scanf("%d", &N);
    for(int i = 1; i < N; i++) {
        int u = read() - 1, v = read() - 1;
        addedge(u, v);
    }
    for(int i = 0; i < N; i++) scanf("%d", w + i);
}
 
void dfs(int x, int fa = -1) {
    mx[x] = cnt[x] = 0;
    for(edge* e = head[x]; e; e = e->next) if(e->to != fa) {
        dfs(e->to, x);
        //
        ans = max(ans, w[x] * mx[e->to]);
        ans = max(ans, w[e->to] * mx[x]);
        tot = (tot + w[x] * cnt[e->to] + w[e->to] * cnt[x]) % MOD;
        (cnt[x] += w[e->to]) %= MOD;
        mx[x] = max(mx[x], w[e->to]);
    }
}
 
int main() {
     
    init();
    dfs(0);
    printf("%d %d\n", ans, tot * 2 % MOD);
     
    return 0;
}
