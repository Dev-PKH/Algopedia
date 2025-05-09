#include <bits/stdc++.h>
using namespace std;

int board[502][502];
int n,m,b;
int sec= 0xfffffff,height;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> b;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> board[i][j];
	
	for(int h=0; h<=256; h++)
	{
		int cnt = b;
		int t = 0;
		for(int x=0; x<n; x++)
		{
			for(int y=0; y<m; y++)
			{
				int cmp = board[x][y] - h;
				
				if(cmp == 0) continue;
				else if(cmp > 0)
				{
					t += cmp * 2;
					cnt += cmp;
				}
				else
				{
					t += cmp * -1;
					cnt += cmp;
				}
			}
		}
		
		if(cnt >=0 && t <= sec)
			{
				sec = t;
				height = h;
			}
	}
	
	cout << sec << ' ' << height;
	
	return 0;
}