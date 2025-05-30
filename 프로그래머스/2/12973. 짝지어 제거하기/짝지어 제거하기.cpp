#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    int answer = 1;
    stack<char> st;
    st.push(s[0]);
    
    for(int i=1; i<s.length(); i++)
    {
        if(!st.empty())
        {
            if(st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
        else st.push(s[i]);
    }
    
    if(st.size() > 0) answer = 0;

    return answer;
}