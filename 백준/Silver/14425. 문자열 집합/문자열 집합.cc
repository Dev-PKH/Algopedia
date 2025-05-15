#include <bits/stdc++.h>
using namespace std;

const int MX = 10000 * 500 + 5; // n * 문자 최대길이 + 여유 길이
int nxt[MX][26]; // 트라이 알고리즘을 사용할 트리 배열
bool chk[MX]; // 끝 노드를 파악하는 용도
int root = 1;
int unused = 2; // 현재 사용 가능한 Index
int n,m, cnt;

void Init()
{
	fill(nxt[0], nxt[MX-1] + 26, -1);
}

int c2i(char c) // char to int
{
	return c - 'a';
}

void Insert(string& s)
{
	int cur = root;
	for(auto c : s)
	{
		if(nxt[cur][c2i(c)] == -1)
			nxt[cur][c2i(c)] = unused++;
		cur = nxt[cur][c2i(c)];
	}
	chk[cur] = true;
}

bool Find(string& s)
{
	int cur = root;
	for(auto c:s)
	{
		if(nxt[cur][c2i(c)] == -1) return false;
		cur = nxt[cur][c2i(c)];
	}
	return chk[cur];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	Init();
	
	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;
		Insert(s);
	}
	
	for(int i=0; i<m; i++)
	{
		string s;
		cin >> s;
		if(Find(s)) cnt++;
	}
	
	cout << cnt;
	
	return 0;
}