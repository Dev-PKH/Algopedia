#include <bits/stdc++.h>
using namespace std;

unordered_set<string> p;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string name, word;
		cin >> name >> word;
		
		if(word.compare("enter")==0) p.insert(name);
		else p.erase(name);
	}
	
	vector<string> v(p.begin(), p.end());
	sort(v.begin(), v.end(), greater<>());
	
	for(auto s : v) cout << s << '\n';
	
	return 0;
}