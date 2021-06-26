#include "utils.h"

class Solution {
public:
    //用一个滑标cursor表示当前位置，从左往右逐个搜索groups中的数组
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int cursor=0;
        for(int i=0;i<groups.size();i++){
            //方便起见，用v代称groups[i]
            auto&v=groups[i];
            bool findsame=false;
            while(cursor+v.size()<=nums.size()){
                findsame=true;
                for(int j=0;j<v.size();j++){
                    if(v[j]!=nums[cursor+j]){
                        findsame=false;
                        break;
                    }
                }
                if(findsame)break;
                else cursor++;
            }
            //找到之后，cursor右移v.size()
            if(findsame)cursor+=v.size();
            else return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi groups=makevvi("[[1,-1,-1],[3,-2,0]");
    vi nums{1,-1,0,1,-1,-1,3,-2,0};
    auto ans=sol.canChoose(groups,nums);
    DBG(ans);

    system("pause");
    return 0;
}
