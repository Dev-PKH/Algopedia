#include <iostream>
#include <stack>
using namespace std;

int main() {
	
	int num, i;
	string str;
	cin >> num;
	
	while(num--){
		cin.clear();
		stack<char> vps;
		cin >> str;
		
		for(i=0; i<str.size(); i++){
			if(str[i] == '('){
				vps.push(str[i]);
			}
			else if(str[i] == ')'){
				if(!vps.empty()) vps.pop();
				else break;
			}
		}
		if(vps.empty() && i == str.size()) cout << "YES";
		else cout << "NO";
		cout << '\n';
		
	}
	
	return 0;
}