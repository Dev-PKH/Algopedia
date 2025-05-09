#include <bits/stdc++.h>
using namespace std;

int m,n,x,y;

int GCD(int a, int b)
{
	if(b==0) return a;
	return GCD(b, a%b);
}

int LCM(int a, int b)
{
	return a / GCD(a,b) * b;
}

int kaing()
{
	int l = LCM(m,n);
	
	if(m==x) x= 0;
	if(n==y) y= 0;
	
	for(int i=x; i<=l; i+=m)
	{
		if(i==0) continue;
		if(i%n==y) return i;
	}
	
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		int num;
		cin >> m >> n >> x >> y;
		cout << kaing() << '\n';
	}
	
	return 0;
}