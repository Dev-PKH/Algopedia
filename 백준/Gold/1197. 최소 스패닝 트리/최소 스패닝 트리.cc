#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> edge[100005];
vector<int> p(10005, -1);
int v,e;

int find(int x)
{
	if(p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool groupCheck(int n1, int n2)
{
	n1 = find(n1); n2 = find(n2);
	if(n1 == n2) return 0;
	if(p[n1] == p[n2]) p[n1]--;
	if(p[n1] < p[n2]) p[n2] = n1;
	else p[n1] = n2;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e;
	for(int i=0; i<e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = {c,a,b};
	}
	
	sort(edge, edge + e);
	int cnt = 0;
	int ans = 0;
	for(int i=0; i<e; i++)
	{
		int a, b, c;
		tie(c,a,b) = edge[i];
		if(!groupCheck(a,b)) continue;
		ans += c;
		cnt++;
		if(cnt == v-1) break;
	}
	
	cout << ans;
	
	return 0;
}