#include <bits/stdc++.h>
using namespace std;

#define ll long long

int arr[100002];
ll sum[100002], hsum[100002]; // 원가 누적합, 할인가 누적합

int n, b, a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b >> a;
    for (int i=1; i<=n; i++) cin >> arr[i];

	sort(arr+1, arr+n+1);
	
	for(int i=1; i<=n; i++)
	{
		sum[i] = sum[i-1] + arr[i];
		hsum[i] = hsum[i-1] + arr[i]/2;
	}

	int cnt = 0;
	for(int i=n; i>0; i--)
	{
		if(sum[i]<=b)
		{
			cnt = i;
			break;
		}
		else
		{
			int k = min(i, a);
			ll num = sum[i] - ((sum[i]-sum[i-k]) - (hsum[i] - hsum[i-k]));
			
			if(num <= b)
			{
				cnt = i;
				break;
			}
		}
	}
	
	cout << cnt;
}