#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[1002][1002];
int dis[1002][1002];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<pair<int,int>> Q;
	cin >> m >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
			if(board[i][j] == 1) Q.push({i,j});
			else if(board[i][j] == 0) dis[i][j] = -1;
		}
	}
	
	while(!Q.empty())
	{
		pair<int,int> cur = Q.front(); Q.pop();
		for(int k=0; k<4; k++)
		{
			int nx = cur.X + dx[k], ny = cur.Y + dy[k];
			if(nx <0 || ny <0 || nx >= n || ny >=m) continue;
			if(dis[nx][ny] > -1) continue;
			Q.push({nx,ny});
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
		}
	}
	
	int day =0;
	for(int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if(dis[i][j] == -1) {cout << -1; return 0;}
			else if(dis[i][j] > day) day = dis[i][j];
		}
	}
	
	cout << day;

	return 0;
}