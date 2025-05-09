#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int modular(ll a, ll b, ll c)
{
	if(b==1) return a%c; // base condition (a^1 mod c를 의미)
	ll val = modular(a,b/2,c); //a^K(b/2) mod c를 구함
	val = val * val % c; // 현재는 2K이므로 val^2 mod c를 진행 (val = a^K mod c)
	if(b%2 == 1) return val * a % c; // 만약 b가 홀수라면 a가 누락됨을 의미 하므로 해당 부분을 수정
	// ex) 2^5 mod 7 = (2^2 mod 7)^2 mod 7 * 2 mod 7
	return val;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll a, b, c;
	cin >> a >> b >> c;
	cout << modular(a,b,c);
	
	return 0;
}