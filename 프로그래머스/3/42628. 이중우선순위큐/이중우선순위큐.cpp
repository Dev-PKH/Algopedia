#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> o) {
    vector<int> answer;
    multiset<int> s;
    
    for(auto c : o)
    {
        if(c[0] == 'I') s.insert(stoi(c.substr(2)));
        else
        {
            if(s.size() > 0)
            {
                if(c[2] == '1') s.erase(--s.end());
                else s.erase(s.begin());
            }
        }
    }
    
    if(s.size() == 0) { answer.push_back(0); answer.push_back(0); }
    else { answer.push_back(*(--s.end())); answer.push_back(*s.begin());}
    
    return answer;
}