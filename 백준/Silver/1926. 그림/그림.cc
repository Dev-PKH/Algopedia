#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m, cnt=0, result=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	queue<pair<int, int>> q;
	
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> board[i][j];
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(!vis[i][j] && board[i][j] == 1)
			{
				vis[i][j] = 1;
				q.push({i,j});
				int size = 0;
				cnt++;
				
				while(!q.empty())
				{
					auto cur = q.front(); q.pop();
					size++;
					
					for(int idx=0; idx<4; idx++)
					{
						int nx = cur.X + dx[idx], ny = cur.Y + dy[idx];
						if(nx<0 || ny<0 || nx >=n || ny >= m) continue;
						if(vis[nx][ny] || board[nx][ny]==0) continue;
						q.push({nx,ny});
						vis[nx][ny] = 1;
					}
					
				}
				
				if(size > result) result = size;
			}
		}
	}
	
	cout << cnt << '\n' << result;
	
	return 0;
}