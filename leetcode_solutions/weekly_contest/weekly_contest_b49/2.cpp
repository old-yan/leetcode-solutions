#include "utils.h"

class Solution {
    //本函数负责切割单词，返回数组
    vector<string>split(string s){
        int i,j;
        vector<string>res;
        for(i=0;i<s.size();i=j+1){
            for(j=i+1;isalpha(s[j]);j++);
            res.push_back(s.substr(i,j-i));
        }
        return res;
    }
    //本函数负责将长数组挖去一部分，和短数组比较
    bool check(vector<string>&shorter,vector<string>&longer){
        int n=longer.size()-shorter.size();
        if(!n)return shorter==longer;
        for(int i=0;i<=longer.size()-n;i++){
            int j=i+n-1;
            vector<string>tmp;
            for(int k=0;k<i;k++)tmp.push_back(longer[k]);
            for(int k=j+1;k<longer.size();k++)tmp.push_back(longer[k]);
            if(tmp==shorter)return true;
        }
        return false;
    }
public:
    //先把长字符串拆成单个单词的数组，再去检查数组
    bool areSentencesSimilar(string s1, string s2) {
        auto v1=split(s1);
        auto v2=split(s2);
        if(v1.size()<v2.size()){
            return check(v1,v2);
        }
        else{
            return check(v2,v1);
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="bb aa aa bb";
    string s2="aa bb";
    auto ans=sol.areSentencesSimilar(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}
