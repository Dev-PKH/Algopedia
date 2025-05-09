#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[27][27];
vector<int> v;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;

int bfs(int a, int b, int cnt)
{
	queue<pair<int,int>> q;
	q.push({a,b});
	board[a][b] = -1;
	
	while(!q.empty())
	{
		pair<int,int> p = q.front(); q.pop();
		cnt++;
		
		for(int i=0; i<4; i++)
		{
			int nx = dx[i] + p.X;
			int ny = dy[i] + p.Y;
		
			if(nx<0 || ny< 0 || nx>=n || ny>=n) continue;
			if(board[nx][ny] != 1) continue;
		
			board[nx][ny] = -1;
			q.push({nx,ny});
		}
	}
	
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >>n ;
	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;
		for(int k=0; k<s.length(); k++) board[i][k] = s[k] - '0';
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(board[i][j]==1){
				v.push_back(bfs(i,j,0));
			}	
		}
	}
	
	cout << v.size() << '\n';
	
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++)
		cout << v[i] << '\n';
	
	return 0;
}