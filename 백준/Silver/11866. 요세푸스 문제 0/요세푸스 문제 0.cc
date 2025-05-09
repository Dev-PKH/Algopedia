#include <iostream>
#include <queue>
using namespace std;

int main() {
	
	int N,K;
	queue<int> q;
	
	cin >> N >> K;
	
	for(int i=0; i<N; i++) q.push(i+1);
	
	cout << '<';
	
	while(!q.empty()){
		for(int i=0; i<K-1; i++){ //K-1 까지 실행
			q.push(q.front()); //첫번째를 N+1로 옮김
			q.pop(); // 첫번째 삭제
		}//K-1 탈출
		cout << q.front();
		if(q.size() != 1) cout << ", ";
		q.pop();
	}
	
	cout << '>';
	
	return 0;
}