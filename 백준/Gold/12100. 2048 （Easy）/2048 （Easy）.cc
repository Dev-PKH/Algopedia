#include <bits/stdc++.h>
using namespace std;

int board[22][22];
int cb[22][22]; // calculate board

int n;
int cost = 0;

void rotate()
{
	int temp[22][22];
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			temp[i][j] = cb[i][j];
			
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cb[i][j] = temp[n-1-j][i];
}

void combine(int dir)
{
	while(dir--) rotate();
	
	for(int i=0; i<n; i++)
	{
		int temp[22] = {};
		int idx = 0;
		for(int j=0; j<n; j++)
		{
			if(cb[i][j] ==0) continue;
			if(temp[idx] == 0) temp[idx] = cb[i][j];
			else if(temp[idx] == cb[i][j]) temp[idx++] = 2 * cb[i][j];
			else temp[++idx] = cb[i][j];
		}
		
		for(int j=0; j<n; j++) cb[i][j] = temp[j];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> board[i][j];
	
	// 4(상하좌우)^5(5번)의 총 경우의 수만큼 실행
	for(int cnt=0; cnt < (1 << 2*5); cnt++) // 1 << 2*5 = 4^5 = 1024
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) cb[i][j] = board[i][j];
		
		int dir = cnt;
		for(int i=0; i<5; i++)
		{
			combine(dir%4);
			dir /= 4;
		}
		
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cost = max(cost, cb[i][j]);
	}
	
	
	cout << cost;
	return 0;
}