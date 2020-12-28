#include "utils.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char,int>M{{'A',0},{'T',1},{'C',2},{'G',3}};
        bitset<1<<20>appeared;
        bitset<1<<20>repeat;
        ll val=0;
        vector<string>ans;
        for(int i=0,j=0;i+10<=s.size();i++){
            while(j<i+10)val=(val*4+M[s[j++]])%(1<<(20));
            if(!appeared[val]){
                appeared.set(val);
            }
            else if(!repeat[val]){
                repeat.set(val);
                ans.pb(s.substr(i,10));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto ans=sol.findRepeatedDnaSequences(s);
    DBGV(ans);

    system("pause");
    return 0;
}
