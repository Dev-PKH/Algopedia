#include <bits/stdc++.h>
using namespace std;

int d[100002];
int s[100002];
int n,m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) cin >> d[i];
	for(int i=1; i<=n; i++)
		s[i] = d[i] + s[i-1];
	
	while(m--)
	{
		int i,j;
		cin >> i >> j;
		cout << s[j] - s[i] + d[i] << '\n';
	}
	
	return 0;
}