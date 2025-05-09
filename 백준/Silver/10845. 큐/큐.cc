#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num;
	string str;
	queue<int> que;
	cin >> num;
	
	for(int i=0; i<num; i++){
		cin >> str;
		if(str == "push"){
			int value;
			cin >> value;
			que.push(value);
		}
		else if(str == "pop"){
			if(!que.empty()){
				cout << que.front() << '\n';
				que.pop();
			}
			else cout << "-1\n";
		}
		else if(str == "size") cout << que.size() << '\n';
		else if(str == "empty") cout << que.empty() << '\n';
		else if(str == "front"){
			if(!que.empty()) cout << que.front() << '\n';
			else cout << "-1\n";
		}
		else if(str == "back"){
			if(!que.empty()) cout << que.back() << '\n';
			else cout << "-1\n";
		}
		
	}
	
	return 0;
}