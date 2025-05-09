#include <bits/stdc++.h>
using namespace std;

int a[1000002];
int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) 
	{
		cin >> a[i];
		v.push_back(a[i]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()), v.end());
	
	for(int i=0; i<n; i++)
	{
		cout << lower_bound(v.begin(), v.end(), a[i]) - v.begin() << ' ';
	}
	
	return 0;
}