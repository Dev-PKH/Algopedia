#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100002];
int p[100002];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n-1; i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	queue<int> q;
	q.push(1);
	
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		
		for(auto c : adj[cur])
		{
			if(p[c] != 0) continue;
			p[c] = cur;
			q.push(c);
		}
	}
	
	for(int i=2; i<=n; i++)
		cout << p[i] << '\n';
	
	return 0;
}