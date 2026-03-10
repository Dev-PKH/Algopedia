#include <bits/stdc++.h>
using namespace std;

const int mx = 600005;
char arr[mx];
int pre[mx], nxt[mx];
int unused = 1, cursor = 0;

void traversal()
{
	int cnt = nxt[0];
	while(cnt != -1)
	{
		cout << arr[cnt];
		cnt = nxt[cnt];
	}
}

void insert(int idx, char c)
{
	arr[unused] = c;
	pre[unused] = idx;
	nxt[unused] = nxt[idx];
	
	if(nxt[idx] != -1) pre[nxt[idx]] = unused;
	nxt[idx] = unused;
	
	unused++;
}

void erase(int idx)
{
	if(nxt[idx] != -1) pre[nxt[idx]]= pre[idx];
	nxt[pre[idx]] = nxt[idx];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(pre, pre+mx, -1);
	fill(nxt, nxt+mx, -1);

	string s;
	cin >> s;
	
	for(char c:s) insert(cursor++, c);

	int cnt = 0;
	cin >> cnt;
	
	char c;
	
	while(cnt--)
	{
		cin >> c;
		
		if(c == 'P')
		{
			cin >> c;
			
			insert(cursor, c);
			cursor = nxt[cursor];
		}
		else if(c == 'L')
		{
			if(pre[cursor] != -1)
				cursor = pre[cursor];
		}
		else if(c== 'D')
		{
			if(nxt[cursor] != -1)
				cursor = nxt[cursor];
		}
		else
		{
			if(cursor != 0)
			{
				erase(cursor);
				cursor = pre[cursor];
			}
		}
	}
	
	traversal();
	
	return 0;
}