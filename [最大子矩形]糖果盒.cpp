#include <cstdio>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

long n;long m;
long num[1010][1010];
long sum[1000][1010];
long l[1010];
long r[1010];
long maxl[2][1010];
long maxr[2][1010];
long height[1010];

int main()
{
	freopen("candy_box.in","r",stdin);
	freopen("candy_box.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	for (long i=1;i<n+1;i++)
		for (long j=1;j<m+1;j++)
		{
			scanf("%ld",num[i]+j);
			sum[i][j] = num[i][j] + sum[i][j-1];
		}	
	for (long i=1;i<n+1;i++)
		for (long j=1;j<m+1;j++)
			sum[i][j] += sum[i-1][j];
	long ans = 0;
	
	for (long j=1;j<m+1;j++)
	{
		maxl[0][j] = 0;
		maxr[0][j] = m;
	}
	
	for (long i=1;i<n+1;i++)
	{
		//i&1 �ǹ������������ٿռ临�ƶ�
		for (long j=1;j<m+1;j++)
			maxl[i&1][j] = maxr[i&1][j] = 0;
		l[0] = 0;
		r[m+1] = m;
		for (long j=1;j<m+1;j++)
		{
			if (num[i][j])
			{	
				l[j] = l[j-1];
				maxl[i&1][j] = MAX(l[j],maxl[(i&1)^1][j]);
			}
			else
			{
				height[j] = i;
				
				l[j] = j;
				maxl[i&1][j] = -1;
			}	
		}
		for (long j=m;j>0;j--)
		{
			if (num[i][j])
			{
				//����֮������r[j]=j-1��ǰ�����l[j]=j;����Ϊ������ȥ��ʱ�򣬻��j�е�Ҳ���ϣ�һ����ȥ����r�Ĳ���
				r[j] = r[j+1];
				maxr[i&1][j] = MIN(r[j],maxr[(i&1)^1][j]);
			}
			else
			{ 
				r[j] = j-1;
				maxr[i&1][j] = m+1;
			}
		}
 		for (long j=1;j<m+1;j++)
			//��ͬ��ͼƬ����
			ans = MAX(ans,sum[i][maxr[i&1][j]]+sum[height[j]][maxl[i&1][j]]-sum[height[j]][maxr[i&1][j]]-sum[i][maxl[i&1][j]]);
	}
	printf("%ld",ans);
}
