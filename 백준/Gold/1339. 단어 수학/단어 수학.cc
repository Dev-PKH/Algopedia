#include <bits/stdc++.h>
using namespace std;

int word[26];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;
		int cnt = 1;
		for(int j=s.length() - 1; j>=0; j--)
		{
			word[s[j] - 'A'] += cnt;
			cnt *= 10;
		}	
	}

	sort(word, word+26, greater<>());
	
	int result = 0;
	int cnt = 9;
	for(int i=0; i<26; i++)
	{
		if(word[i] == 0) break;
		result += word[i] * cnt--; 
	}

	cout << result;

	return 0;
}