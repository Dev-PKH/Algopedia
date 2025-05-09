#include <bits/stdc++.h>
using namespace std;

int arr[500002];
int n;

int lowIndex(int num)
{
	int st = 0;
	int en = n; // 새로 추가할 num까지의 추가 길이여서
	int mid = (st+en)/2;
	
	
	while(st < en)
	{
		if(arr[mid] >= num) en = mid;
		else st = mid + 1;
		mid = (st+en)/2;
	}
	
	return st;
}

int upIndex(int num)
{
	int st = 0;
	int en = n;
	int mid = (st+en)/2;
	
	while(st < en)
	{
		if(arr[mid] <= num) st = mid+1;
		else en = mid;
		mid = (st+en)/2;
	}
	
	return st;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	
	sort(arr, arr+n);
	
	int m;
	cin >> m;
	
	while(m--)
	{
		int num;
		cin >> num;
		cout << upIndex(num) - lowIndex(num) << ' ';
	}
	
	return 0;
}