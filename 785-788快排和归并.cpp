#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int q[N];

void quick_sort(int l, int r)
{
	if(l >= r)return;
	int i = l - 1, j = r + 1, x = q[l + r >> 1];
	while(i < j)
	{
		do i++;while(q[i] < x);
		do j--;while(q[j] > x);
		if(i < j)swap(q[i], q[j]);
	}
	quick_sort(l, j);
	quick_sort(j + 1, r);
}

int t[N];

void merge_sort(int l , int r)
{
	if(l >= r)return;
	int mid = l + r >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while(i <= mid && j <= r)
	{
		if(q[i] <= q[j])t[k++] = q[i++];
		else t[k++] = q[j++];
	}
	while(i <= mid)t[k++] = q[i++];
	while(j <= r)t[k++] = q[j++];
	memcpy(q + l, t, (r - l + 1) * sizeof(int));
}

int main()
{
	return 0;
}
