#include <bits/stdc++.h>
using namespace std;

void hanoi(int start, int end, int num)
{
	if(num == 1)
	{
		cout << start << ' ' << end << '\n';
		return;
	}
	hanoi(start, 6-start-end, num-1); // n-1개의 원판을 목적지가 아닌 기둥으로 이동
	cout << start << ' ' << end << '\n'; // n번째 원판을 목적지로 이동
	hanoi(6-start-end, end, num-1); // n-1개의 원판을 목적지로 이동
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	cout << (1<<n) - 1 << '\n'; // 1<<n은 2^n을 의미하며 왼쪽으로 n칸 만큼 이동을 의미
	hanoi(1,3,n);
	
	return 0;
}