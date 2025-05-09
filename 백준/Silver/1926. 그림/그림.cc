#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) cin >> board[i][j];
	
	queue<pair<int,int>> Q;
	int num=0;
	int max=0;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(vis[i][j] || board[i][j] == 0) continue;
			Q.push({i,j});
			vis[i][j] = 1;
			num++;
			int cnt =1;
			
			while(!Q.empty())
			{
				pair<int,int> cur = Q.front(); Q.pop();
				for(int k=0; k<4; k++)
				{
					int nx = cur.X + dx[k], ny = cur.Y + dy[k];
					if(nx <0 || ny <0 || nx >= n || ny >=m) continue;
					if(vis[nx][ny] || board[nx][ny] == 0) continue;
					Q.push({nx,ny});
					vis[nx][ny] = true;
					cnt++;
				}
			}
			if(cnt > max) max = cnt;
		}
	}
	cout << num << '\n' << max;
	
	return 0;
}