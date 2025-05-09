#include <iostream>
using namespace std;

int main() {
	int cnt[1000009] = {0,};
	int num;
	cin >> num;
	
	for(int i=2; i<=num; i++)
	{
		cnt[i] = cnt[i-1] +1;
		if(i % 2 ==0) cnt[i] = cnt[i] > cnt[i/2] +1 ? cnt[i/2] + 1 : cnt[i];
		if(i % 3 ==0) cnt[i] = cnt[i] > cnt[i/3] +1 ? cnt[i/3] + 1 : cnt[i];
 	}
	
	cout << cnt[num] << '\n';
	
	return 0;
}