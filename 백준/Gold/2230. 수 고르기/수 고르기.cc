#include <bits/stdc++.h>
using namespace std;

int a[100002];
int n,m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> a[i];
	
	sort(a, a+n);
	
	int en = 0;
	int result = 0x7fffffff;
	for(int st = 0; st <n; st++)
	{
		while(en < n && a[en] - a[st] < m) en++;
		if(en == n) break;
		result = min(result, a[en]- a[st]);
	}
	
	cout << result;
	
	return 0;
}