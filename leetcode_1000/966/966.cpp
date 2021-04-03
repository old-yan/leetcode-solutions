#include "utils.h"

class Solution {
    bool isVow[128]={0};
    string to_lower(string s){
        for(char&c:s)c=tolower(c);
        return s;
    }
    string changeVows(string s){
        for(char&c:s){
            if(isVow[c])c='*';
            else c=tolower(c);
        }
        return s;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        isVow['a']=isVow['A']=isVow['e']=isVow['E']=isVow['i']=isVow['I']=isVow['o']=isVow['O']=isVow['u']=isVow['U']=true;
        vector<string>ans;
        unordered_set<string>S(ALL(wordlist));
        unordered_map<string,int>M1,M2;
        REP(i,wordlist.size()){
            string lower=to_lower(wordlist[i]);
            if(!M1.count(lower))M1[lower]=i;
            string Vow=changeVows(wordlist[i]);
            if(!M2.count(Vow))M2[Vow]=i;
        }
        for(string&q:queries){
            if(S.count(q))ans.pb(q);
            else if(M1.count(to_lower(q)))ans.pb(wordlist[M1[to_lower(q)]]);
            else if(M2.count(changeVows(q)))ans.pb(wordlist[M2[changeVows(q)]]);
            else ans.pb("");
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>wordlist{
        "KiTe","kite","hare","Hare"
    };
    vector<string>queries{
        "kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"
    };
    auto ans=sol.spellchecker(wordlist,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
