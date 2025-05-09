#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int n = 9;

vector<pair<int,int>> v;
int board[12][12];
int cnt = 0;
bool isend = false;

bool check(int i, int j, int value)
{
	for(int x=0; x<n; x++)
	{
		if(board[i][x] == value) return false;
		if(board[x][j] == value) return false;
	}
	
	int fx = i/3;
	int fy = j/3;
	fx *= 3;
	fy *= 3;
	
	for(int x=fx; x<fx+3; x++)
	{
		for(int y=fy; y<fy+3; y++)
		{
			if(board[x][y] == value) return false;
		}
	}
	
	return true;
}

void tracking(int value)
{
	if(isend) return;
	if(cnt == value)
	{
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		isend = true;
	}
	else
	{
		int nx = v[value].X;
		int ny = v[value].Y;
		
		for(int i=1; i<=n; i++)
		{
			if(check(nx,ny,i))
			{
				board[nx][ny] = i;
				tracking(value+1);
				board[nx][ny] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 0) v.push_back({i,j});
		}
	
	cnt = v.size();
	tracking(0);
	
	return 0;
}