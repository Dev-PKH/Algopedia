#include <bits/stdc++.h>
using namespace std;

int d[102][100002];
int w[102], v[102];
int n,k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> w[i] >> v[i];
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			if(j >= w[i]) d[i][j] = max(d[i-1][j], d[i-1][j-w[i]] + v[i]);
			else d[i][j] = d[i-1][j];
		}
	}
	
	cout << d[n][k];
	
	return 0;
}