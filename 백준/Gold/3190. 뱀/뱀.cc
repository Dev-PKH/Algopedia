#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int m[102][102];
int x[102];
char c[102];
int n,k,l;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,-1,0,1}; // 오, 위, 왼, 아
int dir; // 방향 인덱스스

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	deque<pair<int,int>> dq;
	dq.push_front({1,1});
	m[1][1] = -1;
	
	cin >> n >> k;
	for(int i=0; i<k; i++)
	{
		int a, b;
		cin >> a >> b;
		m[a][b] = 1;
	}
	
	cin >> l;
	for(int i=0; i<l; i++) cin >> x[i] >> c[i];
	
	int sec = 0;
	int cnt = 0; // 방향카운트

	pair<int, int> head;
	pair<int, int> tail;
	
	while(1)
	{
		sec++;
		head = dq.front();
		tail = dq.back();
		
		int a = head.X;
		int b = head.Y;
		a += dx[dir];
		b += dy[dir];
		
		if(a > n || b > n || a < 1 || b < 1 || m[a][b] == -1) break;
		
		dq.push_front({a,b});
		
		if(m[a][b] == 0)
		{
			m[tail.X][tail.Y] = 0;
			dq.pop_back();
		}
		
		m[a][b] = -1;
		
		if(cnt < l && sec == x[cnt])
		{
			if(c[cnt] == 'D') dir--;
			else dir++;
			
			if(dir < 0) dir = 3;
			else if(dir > 3) dir = 0;
			cnt++;
		}
	}
	
	cout << sec;
	
	return 0;
}