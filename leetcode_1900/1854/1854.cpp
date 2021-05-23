#include "utils.h"

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int inc[2100]={0};
        for(auto&l:logs){
            inc[l[0]]++;
            inc[l[1]]--;
        }
        partial_sum(inc,inc+2100,inc);
        return max_element(inc,inc+2050)-inc;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi logs=makevvi("[[1993,1999],[2000,2010]]");
    auto ans=sol.maximumPopulation(logs);
    DBG(ans);

    system("pause");
    return 0;
}
