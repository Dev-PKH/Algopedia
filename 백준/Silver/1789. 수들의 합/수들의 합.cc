#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long sum=0,s,n=0, i=1;
	cin >> s;
	
	while(sum < s)
	{
		sum += i;
		
		i++;
		n++;
	}
	
	if(sum > s) n--;
	
	cout << n;
	
	return 0;
}