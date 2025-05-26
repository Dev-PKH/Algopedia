#include <bits/stdc++.h>

using namespace std;

// 조합을 구하는 문제
// 0001 : 학번, 0010 : 이름 ... , 1111: 학번,이름,전공,학년

bool checkmini(vector<int> uniquness, int idx)
{
    for(auto v : uniquness)
        if((v&idx) == v) return false; // 후보키 중 최소성 체크 ex) 0011 & 0001 == 0001 (최소성 위배-> 이름은 없어도 되므로)
    return true;
}

int solution(vector<vector<string>> relation) {
    int row = relation.size(); // tuple
    int col = relation[0].size(); // attribute
    int cb = 1 << col; // 전체 조합의수 + 2(0000, 10000)
    vector<int> uq; // uniqueness 목록
    
    for(int i=1; i<cb; i++)
    {
        unordered_set<string> domain; // 속성값 조합 목록
        for(int x=0; x<row; x++)
        {
            string s = "";
            for(int y=0; y<col; y++)
            {
                if(i & (1 << y)) // 속성값 조합 확인 ex) 0111 & 0001 -> 0001(학번 포함)
                    s += relation[x][y];
            }
            domain.insert(s);
        }
        if(domain.size() == row && checkmini(uq, i)) // 조합에 중복이 없는지와 최소성 만족을 확인
            uq.push_back(i); // 유일성 추가
    }
    
    return uq.size();
}