#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=50010;
int n,m,l,r,mx,cnt;
int year[N],w[N];
struct tree{int l,r,mx,lch,rch;}tr[N*2];

void build(int k,int l,int r){
  int mid=(l+r)>>1;
  tr[++cnt].l=l,tr[cnt].r=r;
  if(l==r) return;
  tr[k].lch=cnt+1;build(cnt+1,l,mid);
  tr[k].rch=cnt+1;build(cnt+1,mid+1,r);
}

void ins(int k,int x){
  int mid=(tr[k].l+tr[k].r)>>1,lc=tr[k].lch,rc=tr[k].rch;
  if(tr[k].l==tr[k].r){tr[k].mx=w[x];return;}
  if(x>mid) ins(rc,x);else ins(lc,x);
  tr[k].mx=max(tr[lc].mx,tr[rc].mx);
}

int query_max(int k,int l,int r){
  if(l>r) return 0;
  int mid=(tr[k].l+tr[k].r)>>1,lc=tr[k].lch,rc=tr[k].rch;
  if(tr[k].l==l&&tr[k].r==r) return tr[k].mx;
  if(r<=mid) return query_max(lc,l,r);
  else if(l>mid) return query_max(rc,l,r);
  else return max(query_max(lc,l,mid),query_max(rc,mid+1,r));
}

//���ģ���true��false��maybe�ķ������۳������ѵ㣻�㷨�������߶����������ѯ���ֵ
int main(){
  scanf("%d",&n);
  build(1,1,n);
  for(int i=1;i<=n;i++) scanf("%d%d",&year[i],&w[i]),ins(1,i);
  scanf("%d",&m);
  for(int i=1;i<=m;i++){
  scanf("%d%d",&l,&r);
  if(r==year[1]||l==year[n]) {printf("maybe\n");continue;}
  int x=lower_bound(year+1,year+1+n,l)-year;

//ȡ��year[x/y]>=l/r����Сx/yֵ
  int y=lower_bound(year+1,year+1+n,r)-year;
  int xx=(year[x]==l),yy=(year[y]==r);

//���l�������ݣ���year[x]ӦΪl��
//��2000 2001 2003 2004 2005 ����2002�����������2003�����ȣ�˵����l�������û��
  if(!xx&&!yy) {printf("maybe\n");continue;}

//��r�����ݣ���l������
  if(!xx&&yy){
//���ֵ
  mx=query_max(1,x,y-1);
//���[x,y-1]�����ֵ������y�������Ϊ�������У����򣬲�����
  if(mx<w[y]) printf("maybe\n");else printf("false\n");
  continue;
  }
//ͬ��
  if(xx&&!yy){
  mx=query_max(1,x+1,y-1);
  if(mx<w[x]) printf("maybe\n");else printf("false\n");
  continue;
  }
  if(xx&&yy) {
//Y��Ľ�����������X��
  if(w[x]<w[y]) {printf("false\n");continue;};
  mx=query_max(1,x+1,y-1);
//���ֵҪС��r��
  if(mx>=w[y]){printf("false\n");continue;}
//�м���δȷ��ֵ��
  if((y-x)!=(year[y]-year[x])) {printf("maybe\n");continue;}
//�ж��꣬ʣ�µľ���true
  printf("true\n");
  }
  }
}
