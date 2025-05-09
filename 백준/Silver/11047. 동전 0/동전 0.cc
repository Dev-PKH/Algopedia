#include <bits/stdc++.h>
using namespace std;

int s[12];
int n, k;
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> s[i];
	
	for(int i=n; i>0; i--)
	{
		cnt += k / s[i];
		k %= s[i];
	}
	
	cout << cnt;
	
	return 0;
}