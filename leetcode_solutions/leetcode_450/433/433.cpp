#include "utils.h"

class Solution {
    unordered_map<char,int>M{
        {'A',0},{'T',1},{'C',2},{'G',3}
    };
    int code(string&s){
        int val=0;
        for(char c:s)val=val*4+M[c];
        return val;
    }
public:
    int minMutation(string _start, string _end, vector<string>& bank) {
        int start=code(_start);
        int end=code(_end);
        bitset<1<<16>B;
        for(auto&s:bank)B.set(code(s));
        queue<int>Q;
        Q.emplace(start);
        B.reset(start);
        int step=0;
        while(int l=Q.size()){
            step++;
            while(l--){
                auto p=Q.front();
                Q.pop();
                REP(i,8){
                    int new_code=p&~(3<<(14-i*2));
                    REP(j,4){
                        if(new_code!=p){
                            if(B[new_code]){
                                if(new_code==end)return step;
                                B.reset(new_code);
                                Q.emplace(new_code);
                            }
                        }
                        new_code+=(1<<(14-i*2));
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string start="AAAAACCC";
    string end="AACCCCCC";
    vector<string>bank{"AAAACCCC", "AAACCCCC", "AACCCCCC"};
    auto ans=sol.minMutation(start,end,bank);
    DBG(ans);

    system("pause");
    return 0;
}
