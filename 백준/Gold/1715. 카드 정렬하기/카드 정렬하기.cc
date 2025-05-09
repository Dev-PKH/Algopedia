#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while(n--)
	{
		int num;
		cin >> num;
		pq.push(num);
	}
	
	int sum = 0;
	while(pq.size() > 1)
	{
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		sum += a+b;
		pq.push(a+b);
	}
	
	cout << sum;
	
	return 0;
}