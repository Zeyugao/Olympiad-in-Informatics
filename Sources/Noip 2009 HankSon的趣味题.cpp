/*
1�� x �� a0 �����Լ���� a1�� 
2�� x ��b0 ����С�������� b1�� 


1.gcd(x,a0)=a1  => gcd(x/a1,a0/a1)=1
2.//x*b0/gcd(x,b0)=b1 => ��x*(b0/gcd(x,b0))=b1
  //                     ��gcd(x,b1/b0)=1
  //�е����
  //
  My opinion: x*b0/gcd(x,b0)=b1 => gcd(b1/x,b1/b0)=1;
  
  
         ���Ͽ�֪��xһ��Ϊb1��һ��Լ������ôֱ�Ӵ�1��sqrt(b1)����ö�٣��ҵ�x�����ж��Ƿ����Ҫ�󼴿ɡ�
*/
//��һ�������ˣ��� 
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int ans;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int T,i,j,a0,a1,b0,b1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        //len=sqrt(b1+0.5);
        ans=0;
        for(i=1;i*i<=b1;i++)
        {
            if(b1%i==0){
                if(i%a1==0&&(gcd(i/a1,a0/a1)==1)&&(gcd(b1/b0,b1/i)==1))
                  ans++;
                j=b1/i;
                // ����Ӧ���ǣ�
				//����ֻѭ������n�������в���û��ö�ٵ���j=b1/iӦ��Ҫ֤����ʱ�临�Ӷ�O((��n)logn) 
				//���ѭ����n���Ͳ���������䣬ʱ�临�Ӷ�O(nlogn) ��ʱ�� 
                if(j%a1!=0||i==j) continue;
                if((gcd(j/a1,a0/a1)==1)&&(gcd(b1/b0,b1/j)==1))
                  ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

//��һ������û��̫�� 
#include<cstdio>
#include<cmath>
using namespace std;

int gcd(int x,int y)
{
  int t;
  while(x%y)t=x%y,x=y,y=t;
  return y;
}

int main()
{
  int a0,a1,b0,b1;
  int i,j,k,n,x,y,z,sum;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
	  x=a0/a1,y=b1/b0,z=(int)sqrt(b1*1.0);
	  for(sum=0,j=1;j<=z;j++)if(b1%j==0)
	    {
	      if(j%a1==0 && gcd(j/a1,x)==1 && gcd(b1/j,y)==1)sum++;
	      
	      if((b1/j)%a1==0 && gcd((b1/j)/a1,x)==1 && gcd(j,y)==1)sum++;
	    }
	  if(z*z==b1 && z%a1==0 && gcd(z/a1,x)==1 && gcd(z,y)==1)sum--;  
	  printf("%d\n",sum);		
    }
  return 0;
}
