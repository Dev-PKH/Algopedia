#include <bits/stdc++.h>
using namespace std;

int a[100002];
int n,s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	for(int i=0; i<n; i++) cin >> a[i];
	
	int result = 0x7fffffff;
	int sum = 0;
	int en = 0;
	for(int st=0; st<n; st++)
	{
		while(en < n && sum < s)
			sum += a[en++];
			
		if(sum >= s) result = min(result, en-st);
		sum -= a[st];
	}
	
	if(result == 0x7fffffff) cout << 0;
	else cout << result;
	
	return 0;
}