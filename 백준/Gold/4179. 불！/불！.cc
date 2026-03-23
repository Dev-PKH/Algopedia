#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string s[1002];
int jp[1002][1002];
int fp[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int r,c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<pair<int,int>> j;
	queue<pair<int,int>> f;
	
	cin >> r >> c;
	
	for(int i=0; i<r; i++) 
	{
		fill(jp[i], jp[i]+c, -1);
		fill(fp[i], fp[i]+c, -1);
	}
	
	for(int x=0; x<r; x++)
	{
		cin >> s[x];
	}
	
	for(int x=0; x<r; x++)
	{
		for(int y=0; y<c; y++)
		{
			if(s[x][y] == 'J') 
			{
				j.push({x,y});
				jp[x][y] = 0;
			}
			else if(s[x][y] == 'F') 
			{
				f.push({x,y});
				fp[x][y] = 0;
			}
		}
	}

	while(!f.empty())
	{
		auto cur = f.front(); f.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx=cur.X+dx[i], ny=cur.Y+dy[i];
			if(nx<0||ny<0||nx>=r||ny>=c) continue;
			if(s[nx][ny] == '#' || fp[nx][ny] >= 0) continue;
			fp[nx][ny] = fp[cur.X][cur.Y]+1;
			f.push({nx,ny});
		}
	}
	

	while(!j.empty())
	{
		auto cur = j.front(); j.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx=cur.X+dx[i], ny=cur.Y+dy[i];
			if(nx<0||ny<0||nx>=r||ny>=c)
			{
				cout << jp[cur.X][cur.Y] + 1;
				return 0;
			}
			if(s[nx][ny] == '#' || jp[nx][ny] >=0) continue;
			if(fp[nx][ny] != -1 && fp[nx][ny] <= jp[cur.X][cur.Y] + 1) continue;
			j.push({nx,ny});
			jp[nx][ny] = jp[cur.X][cur.Y]+1;
		}
	}
	
	
	cout << "IMPOSSIBLE";
	
	return 0;
}