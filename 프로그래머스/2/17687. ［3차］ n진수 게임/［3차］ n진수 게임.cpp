#include <bits/stdc++.h>

using namespace std;

const string hexa = "0123456789ABCDEF";

string hexing(int idx, int n)
{
    if(idx < n) return string(1,hexa[idx%n]);
    return hexing(idx/n, n) + hexa[idx%n];
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string result = "";
    
    for(int i=0; result.length()<t*m; i++)
        result += hexing(i, n);
    
    int cnt = 0;
    for(auto c : result)
    {
        cnt++;
        if(cnt == p && t > 0) {answer += c; t--;}
        if(cnt == m) cnt = 0;
    }
    
    return answer;
}