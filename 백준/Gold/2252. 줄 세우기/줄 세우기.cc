#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32005];
queue<int> q;
int indegree[32005];
int n, m;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}
	
	for(int i=1; i<=n; i++)
		if(indegree[i] == 0) q.push(i);
	
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		cout << cur << ' ';
		for(auto c : adj[cur])
			if(--indegree[c] == 0) q.push(c);
	}
	
	return 0;
}