#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int len = s.length();
    int answer = len;

    for(int i=1; i<=len/2; i++)
    {
        string str = "";
        string cur = s.substr(0,i);
        int cnt = 1;
        
        for(int j=i; j<len; j+= i)
        {
            string temp = s.substr(j,i);
            if(temp.compare(cur) == 0) cnt++;
            else
            {
                if(cnt > 1) str += to_string(cnt);
                
                str += cur;
                cnt = 1;
                cur = temp;
            }
        }
        
        if(cnt > 1) str += to_string(cnt);
        str += cur;
        answer = min(answer, (int)str.length());
    }
    
    return answer;
}