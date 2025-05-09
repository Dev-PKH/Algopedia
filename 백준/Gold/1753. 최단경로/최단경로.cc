#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pa pair<int,int>

vector<pa> vec[20005]; // cost, Vertex;
priority_queue<pa, vector<pa>, greater<pa>> pq;
int d[20005];
int v,e, st, inf = 0x3fffffff;

void dijkstra(int idx)
{
	pq.push({0,idx});
	
	while(!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if(d[cur.Y] != cur.X) continue;
		for(auto c : vec[cur.Y])
		{
			if(d[c.Y] <= d[cur.Y] + c.X) continue;
			d[c.Y] = d[cur.Y] + c.X;
			pq.push({d[c.Y], c.Y});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e >> st;
	
	fill(d, d+v+1, inf);
	d[st] = 0;
	
	while(e--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		vec[a].push_back({c,b});
	}
	
	dijkstra(st);
	
	for(int i=1; i<=v; i++)
	{
		if(d[i] == inf) cout << "INF\n";
		else cout << d[i] << '\n';
	}
	
	return 0;
}