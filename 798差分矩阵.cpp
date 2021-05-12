/*Ç°×ººÍ²î·Ö*/ 

#include <iostream>
#include <cmath>


using namespace std;
const int N = 1e3 + 5;
int bits[N][N], a[N][N];

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			bits[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];//construct bits 
		}
	}
	while(q--)
	{
		int x1, x2, y1, y2, c;
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
		bits[x1][y1] += c;
		bits[x2 + 1][y2 + 1] += c;
		bits[x1][y2 + 1] -= c;
		bits[x2 + 1][y1] -= c;
	} 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + bits[i][j];
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
    return 0;
}
