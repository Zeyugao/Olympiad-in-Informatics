//1549�������档����Ȼ����Ҫ�����Ż�������
#include<cstdio>
#include<iostream>
#define MAXN 2005
#define LL long long 
using namespace std;

LL use[MAXN][MAXN];
int n,m;
LL ans=0;
LL h[MAXN];
int f[MAXN];
int num[MAXN][2][MAXN];
int q[MAXN][2];

inline LL ab(LL x){return x>0 ? x:-x;}

LL into(){
    char tmp=getchar();
    int re=0;
    while(tmp<'0'||tmp>'9')tmp=getchar();
    while(tmp>='0'&&tmp<='9')re=re*10+(tmp-'0'),tmp=getchar();
    return re;
}

int main(){
    n=into();m=into();
    int i,j,g;
    for(i=1;i<=n;i++)
        h[i]=into();
    int mid,t1,t2,tmp;
    for(i=1;i<=n;i++)
    {
        mid=h[i];
        q[0][0]=0;
        //ͬP1459
        for(j=1;j<=n;j++)
        {
            if(h[j]>mid)f[j]=f[j-1]+1;
            else    if(h[j]<mid)f[j]=f[j-1]-1;
            else    f[j]=f[j-1];   
            q[j][0]=q[j][1]=0;
        }
        //midǰ�����������������ô�������������Ǹ�
        for(j=0;j<i;j++)
        {
            tmp=f[i]-f[j];
            if(tmp>0)t1=tmp,t2=1;
            else if(tmp<0)t1=-tmp,t2=0;
            else  t1=0,t2=0;
            //���棬q[][]���ڴ����ǵڼ����ﵽtmp������
            //num��¼��q[][]���ﵽtmp����ֵ
            num[t1][t2][++q[t1][t2]]=j+1;   
        }
        for(j=i;j<=n;j++)
        {
            tmp=f[j]-f[i];
            if(tmp>0)t1=tmp,t2=0;
            else if(tmp<0)t1=-tmp,t2=1;
            else t1=0,t2=0;
            //��С˳��:num[,,]<mid<i
            //ȡ����g���ﵽtmp���������෴������������Ϊ��˵㣬�Ҷ˵���i��
            for(g=1;g<=q[t1][t2];g++)
                use[num[t1][t2][g]][j]=mid;
        }
    }
    for(i=1;i<=m;i++)
    {
        t1=into();t2=into();
        if((t2-t1)%2==1)mid=use[t1][t2-1];
        else mid=use[t1][t2];
        for(j=t1;j<=t2;j++)
            ans+=ab(h[j]-mid);
    }
    printf("%lld\n",ans);
    return 0;
}
