#include "utils.h"

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>M;
        int minsum=INT_MAX;
        vector<string>ans;
        REP(i,list1.size()){
            M[list1[i]]=i;
        }
        REP(i,list2.size()){
            if(M.count(list2[i])){
                if(chmin(minsum,M[list2[i]]+int(i))){
                    ans={list2[i]};
                }
                else if(minsum==M[list2[i]]+i){
                    ans.pb(list2[i]);
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

    vector<string>list1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string>list2{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    auto ans=sol.findRestaurant(list1,list2);
    DBGV(ans);

    system("pause");
    return 0;
}
