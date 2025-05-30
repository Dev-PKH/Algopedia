#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int len = s.length();
    int answer = len;
    
    
    for(int i=1; i<=len/2; i++)
    {
        string str = "";
        string temp = s.substr(0,i);
        int cnt = 1;
        for(int j=i; j<len; j+=i)
        {
            string cur = s.substr(j,i);
            if(temp.compare(cur) == 0) cnt++;
            else
            {
                if(cnt > 1) str += to_string(cnt);
                str += temp;
                temp = cur;
                cnt = 1;
            }
        }
        
        if(cnt > 1) str += to_string(cnt);
        str += temp;
        answer = min(answer, (int)str.length());
    }
    
    return answer;
}