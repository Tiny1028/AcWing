#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int q[N], s[N];
 
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)scanf("%d", &q[i]);//读入序列 
	int res = 0;
	for(int i = 0, j = 0; i < n;i++)
	{
		s[q[i]]++;
		while(j < i && s[q[i]] > 1)s[q[j++]]--;//前面元素删除，慢指针后移
		res = max(res, i - j + 1); 
	}
	printf("%d\n", res);
	return 0;
 } 
