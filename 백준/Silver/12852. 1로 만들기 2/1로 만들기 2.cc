#include <bits/stdc++.h>
using namespace std;

int d[1000002];
int p[1000002];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=2; i<=n; i++)
	{
		d[i] = d[i-1] + 1;
		p[i] = i-1;
		
		if(i%2 == 0)
		{
			if(d[i] > d[i/2] + 1)
			{
				d[i] = d[i/2] + 1;
				p[i] = i/2;
			}
		}
		
		if(i%3 == 0)
		{
			if(d[i] > d[i/3] + 1)
			{
				d[i] = d[i/3] + 1;
				p[i] = i/3;
			}
		}
	}
	
	cout << d[n] << '\n';
	
	while(n >= 1)
	{
		cout << n << ' ';
		n = p[n];
	}
	
	return 0;
}