#include <cstdio>
#include<cmath>
const int Max = 30001;
int t, father[Max], x, y, r[Max], root[Max];
char ch;
int find(int k) {
                 if (k == father[k]) return k;
                 int temp = find(father[k ]);

                 //1.���ǰһ�������Ǻϲ�����ʱ��father[k]��father[k] = temp;��֪����Ǹ���㣬
                 //             ���ڵ��Ѿ�����Ϊǰһ��εľ��룬��ʱr[k]=r[father[k]]+r[k]���Ǳ���������Ա��θ��ڵ����+���θ���㵽ǰһ��θ����ľ���
                 //             ���ܾ���
                 //2.���ǰһ�β����ǲ�ѯ��r[father[k]]=0��r[k]ֵ����
                 //3.��һ�β�ѯ��r[k]=0��r[father[k]]=0
                r[ k] = r[father[k ]] + r[k];

                 //�����ڵ�ֱ�ӹ��ڸ��ڵ��ϣ�������һ�ε�findʱr[]����
                father[ k] = temp;
                 return temp;
}
int main() {
                scanf( "%d", &t);
                 for (int i = 1; i < Max; i++) {
                                father[i] = i; r[i] = 0, root[i] = 1; //r��ʾ�����ڵ�ľ���
                } //root ��ʾ�����ڵ����
                 while (t--) {
                                getchar();
                                scanf( "%c%d%d", &ch, &x, &y);
                                 int tempx = find(x), tempy = find(y);
                                 if (ch == 'M' ) {
                                                father[tempx] = tempy; //X �ӵ� y
                                                r[tempx] = root[tempy]; //���¾���
                                                root[tempy] += root[tempx]; //�������ڵ����
                                }
                                 else if (tempx != tempy) printf("-1\n");
                                 else printf("%d\n" , (int)fabs(r[x] - r[y]) - 1);
                                                       //ֱ�����ȥͷ/β���ټ�1ȥ��ʣ�µ�
                }
                 return 0;
};
