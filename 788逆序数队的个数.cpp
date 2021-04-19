#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6+10;
int q[N], t[N]; 

//int merge_sort(int q[], int l, int r)
//{
//	if(l >= r)return 0;
//	int mid = l + r >> 1;
//	int res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
//	int i = l, j = mid + 1, k = 0;
//	while(i <= mid && j <= r)
//	{
//		if(q[i] <= q[j])t[k++] = q[i++];
//		else
//		{
//			t[k++] = q[j++];
//			res += mid - i + 1;
//		}
//	}
//	while(i <= mid)t[k++] = q[i++];
//	while(j <= r)t[k++] = q[j++];
//	
//	for(int i = l, j = 0; i <= r; )q[i++] = t[j++]; 
//	return res;
//} 

int merge_sort(int q[], int l, int r)
{
	if(l >= r)return 0;
	int mid = l + r >> 1;
	int res = merge_sort(q, l , mid) + merge_sort(q, mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while(i <= mid && j <= r)
	{
		if(q[i] <= q[j])t[k++] = q[i++];
		else{
			t[k++] = q[j++];
			res += mid - i + 1;//q[j]比q[i,mid]之间的所有元素都小 
		}
	}
	while(i <= mid)t[k++] = q[i++];
	while(j <= r)t[k++] = q[j++];
	memcpy(q + l, t, (r - l + 1) * sizeof(int));
	return res; 
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)scanf("%d", &q[i]);
	int res = merge_sort(q, 0 , n - 1);
	printf("%d\n",res);
	return 0;
}

//归并排序模板
//void merge_sort1(int l, int r)
//{
//	if(l >= r)return;
//	int mid = l + r >> 1;
//	merge_sort1(l, mid);
//	merge_sort1(mid + 1, r);
//	int i = l, j = mid + 1, k = 0;
//	while(i < j)
//	{
//		if(q[i] <= q[j])t[k++] = q[i++];
//		else t[k++] = q[j++];
//	}
//	
//	while(i <= mid)t[k++] = q[i++];
//	while(j <= r)t[k++] = q[j++];
//	memcpy(q + l, t, (r - l + 1) * sizeof(int));
//} 
