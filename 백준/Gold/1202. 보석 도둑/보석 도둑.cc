#include <bits/stdc++.h>
using namespace std;

pair<int,int> jewel[300002];
multiset<int> bag;
int n,k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0; i<n; i++)
	{
		int m,v;
		cin >> m >> v;
		jewel[i] = {v,m};
	}
	
	sort(jewel, jewel+n);
	
	for(int i=0; i<k; i++)
	{
		int c;
		cin >> c;
		bag.insert(c);
	}
	
	long long sum = 0;
	for(int i=n-1;i>=0; i--)
	{
		int m,v;
		tie(v,m) = jewel[i];
		auto it = bag.lower_bound(m);
		if(it == bag.end()) continue;
		sum += v;
		bag.erase(it);
	}
	
	cout << sum;
	
	return 0;
}