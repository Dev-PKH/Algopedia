#include <bits/stdc++.h>
using namespace std;

int a[52], b[52];
int n,s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	
	sort(a, a+n);
	sort(b, b+n);
	
	for(int i=0; i<n; i++) s += a[i] * b[n-i-1];
	
	cout << s;
	
	return 0;
}