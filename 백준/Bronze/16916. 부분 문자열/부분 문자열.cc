#include <bits/stdc++.h>
using namespace std;


string s,p;
int check;

vector<int> failure(string str)
{
	vector<int> f(str.size());
	int j=0;
	
	for(int i=1; i<str.size();i++)
	{
		while(j>0 && str[i] != str[j]) j = f[j-1];
		if(str[i] == str[j]) f[i] = ++j;
	}
	
	return f;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> p;
	
	vector<int> f = failure(p);
	
	int j=0, i=0;
	for(i; i<s.size(); i++)
	{
		while(j>0 && s[i] != p[j]) j = f[j-1];
		if(s[i] == p[j]) ++j;
		if(j == p.size())
		{
			check = 1;
			break;
		}
	}
	
	cout << check;

	return 0;
}