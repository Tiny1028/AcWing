#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> add(vector<int> & A, vector<int> &B)
{
	//input:两个逆序存放的大整数，默认A长度大于B
	//将两个整数依位相加，求余数加入C；进位数加入下一个A，B位的和
	//output：一个逆序存放的大整数和C 
	if(A.size() < B.size())return add(B, A);//如果A数字位数更短交换A,B 
	vector<int> C;
	int t =0;
	for(int i = 0; i < A.size(); i++)
	{
		t += A[i];
		if(i < B.size())t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if(t)C.push_back(t);//有可能位数增加 
	return C;
	
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
	//高精度减法 
	if(A.size() < B.size()) return sub(B, A);
	vector<int> C;
	int t = 0;
	for(int i = 0; i < A.size(); i++)
	{
		t = A[i] - t;
		if(i < B.size())t -= B[i];
		C.push_back((t + 10) % 10);
		if(t < 0)t = 1;//向上借一位 
		else t = 0;
	}
	while(C.size() > 1 && C.back() == 0)C.pop_back();//去除前导0 
	return C;
}

vector<int> mul(vector<int> &A, int b)
{
	//高精度乘低精度 
	vector<int> C;
	int t = 0;
	for(int i = 0; i < A.size() || t; i++)
	{
		if(i < A.size())t += A[i] * b;
		C.push_back(t % 10);//把乘积最末位加入C
		t /= 10;	
	}
//	while(t){
//		C.push_back(t % 10);
//		t /= 10; 
//	}
	while(C.size() > 1 && C.back() == 0) C.pop_back();//当b为0时需要去除前导0	
} 

vector<int> div(vector<int> &A, int b, int &r)//r用来存余数 
{
	//高精度除以低精度
	vector<int> C;
	r = 0;
	for(int i = A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;	
	}
	reverse(C.begin(), C.end());
	while(C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
} 

int main()
{
	string a, b;
	cin >> a >> b;
	vector<int> A, B, C;
	for(int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
	for(int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');//逆向存放大整数
	C = add(A, B); 
	for(int i = C.size() - 1; i >= 0; i--)printf("%d",C[i]);
	return 0;
} 
