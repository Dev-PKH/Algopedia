#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pa pair<int,int>

priority_queue<pa, vector<pa>, greater<pa>> pq;
vector<pa> adj[20002];
int d[20002];
int v,e,st,inf=0x3fffffff;

void dijkstra()
{
	while(!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if(cur.X != d[cur.Y]) continue;
		for(auto c : adj[cur.Y])
		{
			if(d[c.Y] > d[cur.Y] + c.X)
			{
				d[c.Y] = d[cur.Y] + c.X;
				pq.push({d[c.Y],c.Y});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e >> st;
	
	fill(d, d+v+1, inf);
	
	for(int i=0; i<e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
	}
	
	d[st] = 0;
	pq.push({0,st});
	
	dijkstra();
	
	for(int i=1;i<=v;i++)
	{
		if(d[i] == inf) cout << "INF\n";
		else cout << d[i] << '\n';
	}
	
	return 0;
}