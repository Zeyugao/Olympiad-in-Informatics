//Sources:http://www.voidcn.com/blog/qpswwww/article/p-2634025.html 
#include <stdio.h>
#include <stdlib.h>
#define MAXN 100 
#define INF 0x3f3f3f3f 
int ans=INF,n,k;
struct point
{
   int x;//�õ��x����
   int y;//�õ��y���� 
}dots[MAXN];
struct square
{
   struct point l; //���½ǵĵ�l
   struct point r; //���Ͻǵĵ�r 
}sqr[100];
int checkit(int i,int j) //����i��j������֮���Ƿ��г�ͻ(�������������ص�����) 
{
    if(sqr[i].l.x==INF||sqr[i].l.y==INF||sqr[i].r.x==-INF||sqr[i].r.y==-INF)
        return 0;
    if(sqr[j].l.x==INF||sqr[j].l.y==INF||sqr[j].r.x==-INF||sqr[j].r.y==-INF)
        return 0;
    if(sqr[i].l.x>sqr[j].r.x||sqr[i].l.y>sqr[j].r.y)
       return 0;
    if(sqr[j].l.x>sqr[i].r.x||sqr[j].l.y>sqr[i].r.y)
       return 0;
    return 1;
} 
int check() //��鵱ǰ������֪�����Ƿ񶼺Ϸ����Ϸ�����1 
{
    int i,j;
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
           if(checkit(i,j))
               return 0;
    }
    return 1;
}
int getsqr() //������ȡ��ǰ���о��θ������֮�� 
{
    int i,ans=0;
    for(i=0;i<k;i++)
    {
       if(sqr[i].l.x!=INF)
          ans+=(sqr[i].r.x-sqr[i].l.x)*(sqr[i].r.y-sqr[i].l.y);
    }
    return ans;
}
void srch(int now) //Ѱ�ҵ�now����ʱ�����Ƿ��ܸ��� 
{
    if(now==n) //�������
    {
        ans=getsqr(); //��ȡ��ǰ���о��θ������ 
        return;
    }
    int i,j;
    for(i=0;i<k;i++) //�ӵ�0������ѭ����������k-1�����Σ��жϾ����Ƿ񸲸��˵�now
    {
       struct square tmp=sqr[i];  //��������Ѻ�ָ�ԭ״̬ 
       if(sqr[i].l.x>dots[now].x)
           sqr[i].l.x=dots[now].x;
       if(sqr[i].l.y>dots[now].y)
           sqr[i].l.y=dots[now].y;
       if(sqr[i].r.x<dots[now].x)
           sqr[i].r.x=dots[now].x;
       if(sqr[i].r.y<dots[now].y)
           sqr[i].r.y=dots[now].y;
       if(check()&&getsqr()<ans) //����ò���ɺ�֮ǰ���о��ζ��ǺϷ��ģ��ҵ�ǰ����������ľ�������ȵ�ǰ���Ž�С���������(��һ����)���� 
          srch(now+1);
       sqr[i]=tmp;
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
       scanf("%d%d",&dots[i].x,&dots[i].y);
    for(i=0;i<k;i++)
    {
    	//��ʼ��Ϊ���½ǵĵ�ֵΪ��+�ޣ�+�ޣ�
		//���Ͻǵ�ֵΪ(-��,-��)����֤��һ����ӽ���һ������� 
       sqr[i].l.x=INF;
       sqr[i].l.y=INF;
       sqr[i].r.x=-INF;
       sqr[i].r.y=-INF;
    }
    srch(0);
    printf("%d",ans);
    //system("pause");
    return 0;
}

