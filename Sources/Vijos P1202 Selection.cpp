/*���ں�һ���˰���Ѳ���ȡ��,�������ؽ�ȡһ�����ֵf(i+1,j)��f(i,j-1),��ô��ʱȡ�������Ժ�ȡ�õ�������sum(i+1,j)-f(i+1,j)����sum(i,j-1)-f(i,j-1),��ʱȡ�����˰���Ѳ���ȡ��,����ȡQi����Qjʹ��sum(i+1,j)-f(i+1,j)+Qi��sum(i,j-1)-f(i,j-1)+Qj�������нϴ�ֵ.��������Ϸ�Ľ�������Ϸ�Ŀ�ʼ��,���Եõ��ܵ����Ž�.
*/
#include <iostream>
#define Len 1501
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int n,begin,number[Len]={0},dp[Len][Len],sum[Len][Len];
	cin>>n>>begin;
	for(int i =1;i<=n;i++){
		cin>>number[i];
		dp[i][i]=number[i];
		sum[i][i]=number[i];
	}
	for(int i =n-1;i>=1;i--){
		for(int j = i+1;j<=n;j++){
			sum[i][j] = sum[i][j-1]+number[j];
			
			dp[i][j]=max(sum[i+1][j]-dp[i+1][j]+number[i],sum[i][j-1]-dp[i][j-1]+number[j]);
		}
	}
	
	if(begin==1)
	cout<<dp[1][n]<<endl;
	else
	cout<<sum[1][n]-dp[1][n]<<endl;
	return 0;
}
