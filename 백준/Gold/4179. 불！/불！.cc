#include <bits/stdc++.h>
using namespace std;
 
#define X first
#define Y second
string board[1002];
int distF[1002][1002];
int distJ[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	queue<pair<int,int>> QF;
	queue<pair<int,int>> QJ;
 
	cin >> n >> m;
 
	for(int i=0; i<n; i++)
	{
		cin >> board[i];
		for(int j=0; j<m; j++)
		{
			if(board[i][j] == 'F')
			{
				QF.push({i,j});
				distF[i][j] = 1;
			}
			else if(board[i][j] == 'J')
			{
				QJ.push({i,j});
				distJ[i][j] = 1;
			}
		}
	}
 
	while(!QF.empty())
	{
		auto cur = QF.front(); QF.pop();
		for(int i=0; i<4; i++)
		{
			int nx = dx[i] + cur.X, ny = dy[i] + cur.Y;
			if(nx <0 || ny <0 || nx >= n || ny >= m) continue;
			if(board[nx][ny] == '#' ||  distF[nx][ny] != 0) continue;
			QF.push({nx,ny});
			distF[nx][ny] = distF[cur.X][cur.Y] + 1;
		}
	}
	
	while(!QJ.empty())
	{
		auto cur = QJ.front(); QJ.pop();
		for(int i=0; i<4; i++)
		{
			int nx = dx[i] + cur.X, ny = dy[i] + cur.Y;
			if(nx <0 || ny <0 || nx >= n || ny >= m)
			{
				cout << distJ[cur.X][cur.Y];
				return 0;
			}
			if(board[nx][ny] == '#' ||  distJ[nx][ny] != 0) continue;
			if(distF[nx][ny] != 0 && distF[nx][ny] <= distJ[cur.X][cur.Y] + 1) continue;
			QJ.push({nx,ny});
			distJ[nx][ny] = distJ[cur.X][cur.Y] + 1;
		}
	}
	
	cout << "IMPOSSIBLE";
	return 0;
}