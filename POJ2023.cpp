
vijos1549��λ��

//1-n�����еĻ��������Ѿ���֤��ֻ��һ��b��Ȼ�󣬿��Զ���ÿһ�����¼f[i]Ϊ��ǰ������ǰ׺�ͣ�����bΪ1��С��b��Ϊ-1������bΪ0����Ȼ��sum[a][0]��¼b����λ��ǰ�浽��-a�Ĵ�����sum[a][1]���¼����a�Ĵ�����sum[0][0]��¼�ﵽ0�Ĵ��������������Ϳ���o(n)�������ˣ���ϸ�����룺

using namespace std;
const int MAXN=100000+10;
int num[MAXN],f[MAXN],sum[MAXN][2];
int main()
{
    int n,a,b,bri,ans=0;
    scanf("%d%d",&n,&b);   
    for(int i=1;i<=n;i++){
      scanf("%d",&num[i]);
      if(num[i]
      else if(num[i]>b) f[i]=f[i-1]+1;
      else if(num[i]==b){bri=i; f[i]=f[i-1];}
    }
// �ȼ���for(i;p...1) s[i]+=a[i]//num[i]>0 <0 =0
// for(i;p+1...N) s[i]+=a[i]//num[i]>0 <0 =0
//��p�м俪ʼ���ҵ�p����s[]��ֵ��Ϊ0��ֵ
    for(int i=bri-1;i>=0;i--){
      a=f[bri]-f[i];
      if(a<0) sum[-a][0]++;
      else if(a>0) sum[a][1]++;
      else sum[0][0]++;
    }
    for(int j=bri;j<=n;j++){
      a=f[j]-f[bri-1];
      if(a>0) ans+=sum[a][0];
      else if(a<0) ans+=sum[-a][1];
      else ans+=sum[0][0];
     }
cout<<ans<<endl;
return 0;
}

����˼��,����Ҫ<b��������=>b�����ĸ��� 
b�����е�λ��Ϊp
���a[i]>b �Ͷ��� a[i]=1
���a[i]<b �Ͷ��� a[i]=-1
Ȼ����f[j]=a[1]+a[2]+a[3]+...+a[j]

�����f[i]=f[j] (i<=p-1,j>=p),��inc(ans)
����� ans
