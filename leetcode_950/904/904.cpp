#include "utils.h"

class Solution {
    int appear[40001]={0},appear_num=0;
public:
    int totalFruit(vector<int>& tree) {
        int ans=0;
        for(int i=0,j=0;i<tree.size();){
            while(j<tree.size()){
                if(appear_num<2||appear[tree[j]]){
                    if(!appear[tree[j++]]++)appear_num++;
                }
                else break;
            }
            chmax(ans,j-i);
            while(i<tree.size()){
                if(!--appear[tree[i++]]){
                    appear_num--;
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

    vi tree{1,2,3,2,2};
    auto ans=sol.totalFruit(tree);
    DBG(ans);

    system("pause");
    return 0;
}
