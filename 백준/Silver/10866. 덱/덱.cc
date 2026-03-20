#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int arr[2*MX+1];
int head = MX, tail = MX;

void push_front(int x)
{
	arr[head--] = x;
}

void push_back(int x)
{
	arr[++tail] = x;
}

void pop_front()
{
	if(head < tail) head++;
}

void pop_back()
{
	if(tail > head) tail--;
}

bool empty()
{
	return head == tail;
}

int front()
{
	if(!empty()) return arr[head+1];
	else return -1;
}

int back()
{
	if(!empty()) return arr[tail];
	return -1;
}

int size()
{
	return tail - head;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int n, num;
	
	cin >> n;
	
	while(n--)
	{
		cin >> s;
		if(s == "push_front")
		{
			cin >> num;
			push_front(num);
		}
		else if(s == "push_back")
		{
			cin >> num;
			push_back(num);
		}
		else if(s == "pop_front")
		{
			if(empty()) cout << -1 << '\n';
			else
			{
				cout << front() << '\n';
				pop_front();
			}
		}
		else if(s == "pop_back")
		{
			if(empty()) cout << -1 << '\n';
			else
			{
				cout << back() << '\n';
				pop_back();
			}
		}
		else if(s == "size")
		{
			cout << size() << '\n';
		}
		else if(s == "empty")
		{
			if(empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(s == "front")
		{
			cout << front() << '\n';
		}
		else
		{
			cout << back() << '\n';
		}
	}
	
	return 0;
}