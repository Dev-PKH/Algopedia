#include <bits/stdc++.h>
using namespace std;

bool prime[1000002];
int n,m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fill_n(prime, 1000000, true);
	prime[1] = false;
	
	for(int i=2; i*i<=1000000; i++)
	{
		if(!prime[i]) continue;
		for(int j= i*i; j<=1000000; j+=i)
			prime[j] = false;
	}
	
	cin >> m >> n;
	
	for(int i=m; i<=n; i++)
		if(prime[i]) cout << i << '\n';
	
	
	return 0;
}