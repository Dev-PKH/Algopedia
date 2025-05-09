#include <bits/stdc++.h>
using namespace std;

char p[28];
char l[28];
char r[28];
int n;

void Preorder(int st)
{
	cout << p[st];
	if(l[st] != '.') Preorder(l[st]-'A');
	if(r[st] != '.') Preorder(r[st]-'A');
}

void Inorder(int st)
{
	if(l[st] != '.') Inorder(l[st]-'A');
	cout << p[st];
	if(r[st] != '.') Inorder(r[st]-'A');
}

void Postorder(int st)
{
	if(l[st] != '.') Postorder(l[st]-'A');
	if(r[st] != '.') Postorder(r[st]-'A');
	cout << p[st];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		char a,b,c;
		cin >> a >> b >> c;
		
		p[a-'A'] = a;
		l[a-'A'] = b;
		r[a-'A'] = c;
	}
	
	Preorder(0);
	cout << '\n';
	Inorder(0);
	cout << '\n';
	Postorder(0);
	
	return 0;
}