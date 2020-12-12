#include "utils.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vi ans;
        if(words.empty())return ans;
        unordered_map<string,int>M;
        for(string&s:words)M[s]++;
        int l=words[0].size();
        int L=l*words.size();
        for(int i=0,j,k;i<l;i++){
            int extra=M.size();
            for(j=k=i;j+L<=s.size();j+=l){
                while(k<j+L){
                    auto find=M.find(s.substr(k,l));
                    if(find!=M.end()){
                        if(!find->second--)extra++;
                        else if(!find->second)extra--;
                    }
                    k+=l;
                }
                if(!extra)ans.pb(j);
                auto find=M.find(s.substr(j,l));
                if(find!=M.end()){
                    if(!find->second++)extra++;
                    else if(!find->second)extra--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="barfoofoobarthefoobarman";
    vector<string>words{"bar","foo","the"};
    auto ans=sol.findSubstring(s,words);
    DBGV(ans);
    

    system("pause");
    return 0;
}
