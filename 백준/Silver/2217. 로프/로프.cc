#include <bits/stdc++.h>
using namespace std;

int l[100002];
int n, w;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for(int i=0; i<n; i++) cin >> l[i];
	
	sort(l, l+n);
	
	for(int i=1; i<=n; i++)
		w = max(w, l[n-i]*i);
	
	cout << w;
	
	return 0;
}