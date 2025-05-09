#include <bits/stdc++.h>
using namespace std;

int arr[2000002];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int num;
	for(int i=0; i<n; i++)
	{
		cin >> num;
		arr[num + 1000000]++;
	}
	
	for(int i=-1000000; i<1000001;i++)
		while(arr[i+1000000]--) cout << i << '\n';
	
	
	return 0;
}