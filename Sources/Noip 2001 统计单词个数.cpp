//˼·һ��������Ԥ����+dp���ַ��������⣬�������� �о��ܶ����ⶼ�������ַ�����˼����
//�о���string ��O2�Ż��᲻���һ�㣬����ֻ��ʹ��һ�ο�ͷ�����⣬���õ���used���飬Ӧ��Ҳ�ǿ��Ե� 
//�����õ���ö�ٿ�ͷ�����ظ����������vis����û���õ�

 

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char dic[10][200],s[300];
int v[300][300],p,k,n,vis[300],f[300][60];

bool find(int l,int r,int t){
    int len=strlen(dic[t]);
    for(int i=l;i<=r-len+1;i++){
        bool flag=true;
        //if(vis[i]) continue;
        for(int j=0;j<len;j++){
            if(s[i+j]!=dic[t][j]) flag=false; 
        }
        if(flag) v[l][r]++;
    }
    return false;
}

int main(){
    scanf("%d%d",&p,&k);
    for(int i=1;i<=p;i++){
        char t[20];
        scanf("%s",t);
        for(int j=(i-1)*20+1;j<=i*20;j++) s[j]=t[(j-1)%20];
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%s",dic[i]);
        for(int j=1;j<i;j++) if(!strcmp(dic[i],dic[j])) i--,n--;

    }
    //Ԥ����v[i][j]��ʾ[i,j]�������ж��ٸ�����
    for(int i=1;i<=20*p;i++)
        for(int j=i;j<=20*p;j++){
            memset(vis,0,sizeof(vis));
            for(int t=1;t<=n;t++) 
                if(find(i,j,t)) v[i][j]++;
        }
//    for(int i=1;i<=20*p;i++){
//        for(int j=1;j<=20*p;j++)printf("%d ",v[i][j]);
//        printf("\n");
//    }
//        

    //dp���� ����f[i][j]��ʾǰi���ַ� �ֳ�j�����ֵĸ��� ��f[i][j]=max(f[i][j],f[k][j-1]+v[k+1][i]) 0<=k<=i-1;
    for(int j=1;j<=k;j++)
        for(int i=1;i<=20*p;i++)
            for(int t=j-1;t<i;t++)//����Ҫ��j-1��ʼ �����© 
                f[i][j]=max(f[i][j],f[t][j-1]+v[t+1][i]);
    printf("%d",f[20*p][k]);
    return 0;
}
