#include <bits/stdc++.h>
using namespace std;

int d[102][102];
int n,m, inf=0x3fffffff;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	fill(d[0],d[n]+n+1, inf);

	while(m--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
	
	for(int i=1; i<=n; i++) d[i][i] = 0;
	
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(d[i][j] == inf) cout << "0 ";
			else cout << d[i][j] << ' ';
		} cout << '\n';
	}
	return 0;
}