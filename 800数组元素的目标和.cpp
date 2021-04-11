/*
AcWing 800. 数组元素的目标和 
2021.04.11
Tiny
*/

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
int a[N], b[N];

int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	for(int i = 0; i < n; i++)scanf("%d", &a[i]);
	for(int i = 0; i < m; i++)scanf("%d", &b[i]);//读入数组
	for(int i = 0, j = m - 1; i < n; i++)
	{
		while(j >= 0 && b[j] + a[i] > x)j--;
		if(b[j] + a[i] == x)
		{
			cout << i << ' ' << j <<endl;
			break;
		}
	}
	return 0;
}


//另一方案 
class solution{
	public:
		void aim_sum(vector<int> &a, vector<int> &b, int x)
		{
			int i = 0, j = b.size() - 1;
			while(a[i] + b[j] != x)
			{
				if(a[i] + b[j] > x)j--;
				else i++;
			}
			cout << i << ' ' << j << endl;
		}
};
