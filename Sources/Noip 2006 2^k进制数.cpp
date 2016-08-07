/*
2^k������
*/

/*
http://blog.tomtung.com/2007/09/noip06-digital/
��ô������ʵ�͵�ͬ�ڣ�ȡN��������Ӧ��2k2k�������е�Nλ������1����num[1]����Ӧ�����λ��ȡֵ��ΧΪ[1,a0]��
�����2~N����num[i]ȡֵ��Χ��Ϊ[1,2^K)���ִ����е�i(1<=i<N-1)����num[i]��ʼȡ����һֱȡ�����һ���� num[N]��
Ҫ���������� j>i ���� num[j-1]<num[j]����ȡ������������������Ǻܻ����������ѧ�����ˡ�
*/


/*
http://blog.sina.com.cn/s/blog_4c396f4301000bp6.html
 ��Ŀ�е��Ǹ�����һ�Ƕȷ������Ѿ��̺��������Ļ���˼·��������Ŀ������Ϊ��������Ϊ7λ��01�ִ���3λһ�ξ������֣�0 000 000�����г����׶Σ�ÿ�ζ�С��(111)2��Ҳ��С��2k�����׶���Ȼ��С��2w%k������w%kΪ0ʱҲ�������ˡ�
    ����׶�Ϊ0�������2k������λ���ֱ�Ϊ2��3��...��[n/k]ʱ�������b_max��ʾ2k����Ӧ�Ľ�ĸ����ֱ�ΪC[b_max-1][2]��C[b_max-1][3]��...��C[b_max-1][n/k]��C[i][j]��ʾ��i������ѡj������һ����ϣ���
    ����׶β�Ϊ0�����׶�Ϊx��������c[b_max-x-1][n/k]����
    ���������ĸ����͸㶨�ˣ�ʣ�µĻ���Ǹ߾��ˡ�������������������ʽ��C[n][m]=C[n-1][m-1]+C[n-1][m]�������߾���ֻ�üӷ��ˡ�
*/
/*http://www.yniverse.net/noip2006-2knum/

*/
#include <fstream>
#include <iostream>
using namespace std;
int c[512][512][100];
void plus1(int*,int*,int*);
void plus2(int*,int*);
int main() {
    //ifstream fin ("digital.in");
    //ofstream fout ("digital.out");
    int k,n,b_max,h_max,ans[201]={0};
    /*fin*/cin >> k >> n;
    b_max=1<<k;
    h_max=1<<(n%k);
    c[0][0][0]=c[0][0][1]=1;
    for (int i=1;i<b_max;i++) for (int j=0;j<=i;j++) {
        if (j==0) c[i][j][0]=c[i][j][1]=1;
        else plus1(c[i-1][j],c[i-1][j-1],c[i][j]);
    }
    for (int i=2;i<=n/k && i<b_max;i++) plus2(ans,c[b_max-1][i]);
    for (int i=1;i<h_max && n/k+i<b_max;i++) plus2(ans,c[b_max-i-1][n/k]);
    for (int i=ans[0];i>=1;i--) fout << ans[i];
    /*fout*/cout << endl;
    //fin.close();
    //fout.close();
    return 0;
}
void plus1(int x[],int y[],int z[]) {
    z[0]=max(x[0],y[0]);
    for (int i=1;i<=z[0];i++) {
        z[i]+=x[i]+y[i];
        z[i+1]+=z[i]/10;
        z[i]%=10;
    }
    if (z[z[0]+1]!=0) z[0]++;
}
void plus2(int x[],int y[]) {
    x[0]=max(x[0],y[0]);
    for (int i=1;i<=x[0];i++) {
        x[i]+=y[i];
        x[i+1]+=x[i]/10;
        x[i]%=10;
    }
    if (x[x[0]+1]!=0) x[0]++;
}
