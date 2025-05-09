#include <bits/stdc++.h>
using namespace std;

long long arr[100002];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++) cin >> arr[i];
	
	sort(arr, arr+n);
	
	int cnt = 1;
	long long val = arr[0];
	int mxcnt = 1;
	
	for(int i=1; i<n; i++)
	{
		if(arr[i] == arr[i-1]) cnt++;
		else
		{
			if(mxcnt < cnt)
			{
				mxcnt = cnt;
				val = arr[i-1];
			}
			cnt = 1;
		}
	}
	
	if(mxcnt < cnt) val = arr[n-1];
	
	cout << val;
	
	return 0;
}