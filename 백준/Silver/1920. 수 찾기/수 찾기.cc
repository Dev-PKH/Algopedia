#include <bits/stdc++.h>
using namespace std;

int arr[100002];
int n;

bool binarysearch(int num)
{
	int st = 0;
	int en = n-1;
	while(st <= en)
	{
		int mid = (st+en)/2;
		if(arr[mid] == num) return 1;
		else if(arr[mid] < num) st = mid+1;
		else en = mid-1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	
	sort(arr, arr + n);
	
	int m;
	cin >> m;
	
	while(m--)
	{
		int num;
		cin >> num;
		cout << binarysearch(num) << '\n';
	}
	
	return 0;
}