#include <bits/stdc++.h>
using namespace std;

int d[1002][1002]; // d[n][k] = nCk의 값
int n,k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for(int i=1; i<=1000; i++)
	{
		d[i][0] = d[i][i] = 1;
		for(int j=1; j<i; j++)
		{
			d[i][j] = (d[i-1][j] + d[i-1][i-j])%10007 ; // nCk = (n-1)Ck + (n-1)C(n-k)를 이용
		}
	}
	
	cout << d[n][k];
	
	return 0;
}