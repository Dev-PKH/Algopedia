#include <bits/stdc++.h>
using namespace std;

int d[10002]; // d[i]는 i번째 동전을 만들기 위한 경우의 수
int coin[102];
int n,k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> coin[i];
	
	d[0] = 1; // 동전을 안쓰고 만드는 방법
	
	for(int i=0; i<n; i++)
	{
		for(int j=coin[i]; j<=k; j++)
		{
			d[j] += d[j-coin[i]];
		}
	}
	
	cout << d[k];
	
	return 0;
}