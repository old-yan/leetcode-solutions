#include "utils.h"

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        //本题注意人的编号从1开始，语言的编号也是从1开始
        //b[i]表示i号人掌握的语言
        bitset<501>b[languages.size()+1];
        for(int i=0;i<languages.size();i++){
            for(int language:languages[i]){
                b[i+1].set(language);
            }
        }
        int ans=INT_MAX;
        //以i作为编号暴力搜索各种语言
        for(int i=1;i<=n;i++){
            bitset<501>temp;
            for(auto&A:friendships){
                int j=A[0],k=A[1];
                //如果有共同语言，则不需要额外的学习
                if((b[j-1]&b[k-1]).count())continue;
                //没有共同语言，则需学习语言i
                if(!b[j-1][i])temp.set(j);
                if(!b[k-1][i])temp.set(k);
            }
            ans=min(ans,int(temp.count()));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    

    system("pause");
    return 0;
}
