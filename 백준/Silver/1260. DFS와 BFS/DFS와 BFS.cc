#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1002];
bool dv[1002];
bool bv[1002];
int n, m, s;

void DFS(int st)
{
	if(dv[st]) return;
	cout << st << ' ';
	dv[st] = true;
	for(auto v : adj[st])
	{
		if(dv[v]) continue;
		DFS(v);
	}
}

void BFS(int st)
{
	queue<int> q;
	q.push(st);
	while(!q.empty())
	{
		int c = q.front(); q.pop();
		bv[c] = true;
		cout << c << ' ';
		for(auto v : adj[c])
		{
			if(bv[v]) continue;
			bv[v] = true;
			q.push(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n >> m >> s;
	
	for(int i=0; i< m; i++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++)
		sort(adj[i].begin(), adj[i].end());
	
	DFS(s);
	cout << '\n';
	BFS(s);
	
	return 0;
}