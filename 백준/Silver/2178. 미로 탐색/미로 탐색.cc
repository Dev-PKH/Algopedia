#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[102][102];
int dis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int x=0; x<n; x++)
	{
		string s;
		cin >> s;
		
		for(int y=0; y<s.length(); y++)
			board[x][y] = s[y] - '0';
	}
	
	queue<pair<int,int>> q;
	q.push({0,0});
	dis[0][0] = 1;
	
	while(!q.empty())
	{
		auto cur = q.front(); q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx=cur.X+dx[i], ny=cur.Y+dy[i];
			
			if(nx<0 || ny<0 || nx >=n || ny >=m) continue;
			if(board[nx][ny] == 0) continue;
			if(dis[nx][ny] != 0 && dis[nx][ny] <= dis[cur.X][cur.Y]+1) continue;
			dis[nx][ny] = dis[cur.X][cur.Y]+1;
			q.push({nx,ny});
		}
	}
	
	cout << dis[n-1][m-1];
	
	
	return 0;
}