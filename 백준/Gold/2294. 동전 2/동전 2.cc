#include <bits/stdc++.h>
using namespace std;

int d[100002]; // d[i] = i값에 대하여 최소 동전 거스름 횟수
int coin[102];
int n,k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> coin[i];
	
	fill(d, d+k+1, 100002);
	d[0] = 0; // 동전을 아예 안줄 경우
	sort(coin, coin+n);
	
	for(int i=1; i<=k; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(coin[j] > i) break;
			
			d[i] = min(d[i], d[i-coin[j]]+1);
		}
	}
	
	if(d[k] == 100002) cout << -1;
	else cout << d[k];
	
	return 0;
}