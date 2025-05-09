#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> p;
string rp[100002];
int n,m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		string s;
		cin >> s;
		p[s] = i;
		rp[i] = s;
	}
	
	for(int i=0; i<m; i++)
	{
		string s;
		cin >> s;
		if(p.find(s) != p.end()) cout << p[s] << '\n';
		else cout << rp[stoi(s)] << '\n';
	}
	
	return 0;
}