#include <iostream>
using namespace std;

int main() {
	int k,n;
	cin >> k >> n;
	int arr[k];
	long long max =1;
	int cnt = 0;
	for(int i=0; i<k ; i++){
		scanf("%d",&arr[i]);
		if(max < arr[i]) max = arr[i];
	}
	long long left = 1; // 왼쪽선 좌표
	long long right = max; // 오른선 좌표
	long long mid = 0;
	
	while(left <= right){
		cnt = 0;
		mid = (left+right)/2;
		for(int i=0; i<k ;i++) cnt += arr[i]/mid;
		if(cnt >= n) left = mid +1;
		else right = mid - 1;
	}
	cout << right << endl;
	
	return 0;
}