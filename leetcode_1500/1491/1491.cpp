#include "utils.h"

class Solution {
public:
    double average(vector<int>& salary) {
        int Max=*max_element(ALL(salary)),Min=*min_element(ALL(salary));
        int sum=accumulate(ALL(salary),0);
        return 1.0*(sum-Max-Min)/(salary.size()-2);

    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi salary{4000,3000,1000,2000};
    auto ans=sol.average(salary);
    DBG(ans);

    system("pause");
    return 0;
}
