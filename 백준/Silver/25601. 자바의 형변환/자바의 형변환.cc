#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	unordered_map<string, string> parent;
	
	for(int i=0; i<n-1; i++)
	{
		string a, b;
		cin >> a >> b;
		parent[a] = b; // a의 부모는 b
	}
	
	string a, b;
	cin >> a >> b;
	
	string A = a, B = b;
	
	while(parent[A] != "")
	{
		if(parent[A] == B)
		{
			cout << 1;
			return 0;
		}
		A = parent[A];
	}

	A = a, B = b;
	
	while(parent[B] != "")
	{
		if(parent[B] == A)
		{
			cout << 1;
			return 0;
		}
		B = parent[B];
	}

	cout << 0;

	return 0;
}