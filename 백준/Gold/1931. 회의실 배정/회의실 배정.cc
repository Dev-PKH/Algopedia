#include <bits/stdc++.h>
using namespace std;

pair<int,int> d[100002]; // {end time, st time}
int n;
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> d[i].second >> d[i].first;
	
	sort(d,d +n); // 회의가 먼저 끝나는 순으로 정렬
	
	int t=0;
	for(int i=0; i<n; i++)
	{
		if(t > d[i].second) continue;
		t = d[i].first;
		cnt++;
	}
	
	cout << cnt;
	return 0;
}