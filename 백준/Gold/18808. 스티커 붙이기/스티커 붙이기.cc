#include <bits/stdc++.h>
using namespace std;
 
int laptop[42][42]; // 노트북 크기
int sticker[12][12]; // 스티커
int n,m,k;
int r,c;
int isattach; // 붙여도 되는지 여부
int oprcnt = 0; // 방향을 돌린 횟수
 
void opr(int sr, int sc) // 시작 행렬 위치
{
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(sticker[i][j]==1 && laptop[i+sr][j+sc] == 1)	return;
 
	isattach=true;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(sticker[i][j]==1) laptop[i+sr][j+sc] = 1;
		}
	}
}

void reverse()
{
	int temp[12][12];
	
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++) temp[i][j] = sticker[i][j];
		
	for(int i=0; i<c; i++)
		for(int j=0; j<r; j++) sticker[i][j] = temp[r-j-1][i];
		
	int sw = c;
	c = r;
	r = sw;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int cnt=0;
 
	cin >> n >> m >> k;
 
	while(k--)
	{
		for(int i=0; i<10; i++)
			for(int j=0; j<10; j++) sticker[i][j] = 0;
		
		isattach = false;
		oprcnt = 0;
 
		cin >> r >> c;
 
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++) cin >> sticker[i][j];
 
		while(oprcnt <4)
		{
			for(int i=0; i<=n-r;i++)
			{
				if(isattach) break;
				for(int j=0; j<=m-c;j++)
				{
					opr(i,j);
					if(isattach) break;
				}
			}

			if(isattach) break;
			reverse();
			oprcnt++;
		}
	}
 
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(laptop[i][j] == 1) cnt++;
	
	cout << cnt;
	
	return 0;
}