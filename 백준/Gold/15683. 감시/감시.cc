#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int room[10][10];
int nav[10][10];
int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};
int n,m;

void detect(int x, int y, int dir)
{
	dir %= 4; // 방향 초과 방지
	x += nx[dir]; // 다음 탐지 방향 설정
	y += ny[dir];
	
	if(x < 0 || y < 0 || x >= n || y>= m) return;
	if(nav[x][y] == 6) return;
	
	if(nav[x][y] == 0) nav[x][y] = -1; // 감지완료
	detect(x,y,dir);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<pair<int,int>> cctv;
	int blind = 0;
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> room[i][j];
			if(room[i][j] == 0) blind++;
			else if(room[i][j] < 6) cctv.push_back({i,j});
		}
	}
	
	int cctvcnt = cctv.size();
	
	for(int num=0; num < (1 << (2*cctvcnt)); num++)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) nav[i][j] = room[i][j];
		
		int dir = num;	
		for(int i=0; i<cctvcnt; i++)
		{
			int cdir = dir % 4;
			dir /= 4;
			
			int x = cctv[i].X;
			int y = cctv[i].Y;
			
			if(nav[x][y] == 1) detect(x,y,cdir);
			else if(nav[x][y] == 2)
			{
				detect(x,y,cdir);
				detect(x,y,cdir+2);
			}
			else if(nav[x][y] == 3)
			{
				detect(x,y,cdir);
				detect(x,y,cdir+1);
			}
			else if(nav[x][y] == 4)
			{
				detect(x,y,cdir);
				detect(x,y,cdir+1);
				detect(x,y,cdir+2);
			}
			else if(nav[x][y] == 5)
			{
				detect(x,y,cdir);
				detect(x,y,cdir+1);
				detect(x,y,cdir+2);
				detect(x,y,cdir+3);
			}
		}
		
		int ccnt=0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(nav[i][j] ==0) ccnt++;
			}
		}
		
		if(ccnt < blind) blind = ccnt;
	}
	
	cout << blind;
	
	return 0;
}