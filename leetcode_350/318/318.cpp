#include "utils.h"

class Solution {
public:
    int maxProduct(vector<string>& words) {
        pair<int,int>p[words.size()];
        REP(i,words.size()){
            int mask=0;
            for(char c:words[i]){
                mask|=(1<<(c-'a'));
            }
            p[i]=make_pair(mask,words[i].size());
        }
        sort(p,p+words.size(),[&](pair<int,int>&x,pair<int,int>&y)->bool{return x.second>y.second||(x.second==y.second&&x.first<y.first);});
        int ans=0;
        REP(i,words.size()){
            REP(j,i){
                if(p[i].second*p[j].second<=ans)break;
                if(!(p[i].first&p[j].first)){
                    ans=p[i].second*p[j].second;
                    break;
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

    vector<string>words{"abcw","baz","foo","bar","xtfn","abcdef"};
    auto ans=sol.maxProduct(words);
    DBG(ans);

    system("pause");
    return 0;
}
