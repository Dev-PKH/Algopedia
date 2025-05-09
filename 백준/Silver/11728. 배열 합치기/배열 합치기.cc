#include <bits/stdc++.h>
using namespace std;

int arr1[1000002];
int arr2[1000002];
int arr3[2000004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++) cin >> arr1[i];
	for(int i=0; i<m; i++) cin >> arr2[i];
	
	int a=0, b=0;
	
	for(int i=0; i<n+m; i++)
	{
		if(a == n) arr3[i] = arr2[b++];
		else if(b == m) arr3[i] = arr1[a++];
		else if(arr1[a] < arr2[b]) arr3[i] = arr1[a++];
		else arr3[i] = arr2[b++];
		
		cout << arr3[i] << ' ';
	}
	
	
	return 0;
}