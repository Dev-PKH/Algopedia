#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m, day = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<pair<int,int>> q;
	
	cin >> m >> n;
	
	for(int x=0; x<n; x++)
	{
		for(int y=0; y<m; y++)
		{
			cin >> board[x][y];
			if(board[x][y] == 1)
			{
				q.push({x,y});
			}
		}
	}
	
	int size = q.size();
	
	while(!q.empty())
	{
		auto cur = q.front(); q.pop();
		size--;
		
		for(int i=0; i<4; i++)
		{
			int nx=cur.X+dx[i], ny=cur.Y+dy[i];
			if(nx<0||ny<0||nx>=n||ny>=m) continue;
			if(board[nx][ny] != 0) continue;
			board[nx][ny] = 1;
			q.push({nx,ny});
		}
		
		if(size <= 0)
		{
			day++;
			if(!q.empty()) size = q.size();
		}
	}
	
	for(int x=0; x<n; x++)
	{
		for(int y=0; y<m; y++)
		{
			if(board[x][y] == 0)
			{
				day = 0;
				break;
			}
		}
	}
	
	cout << day-1;
	
	return 0;
}