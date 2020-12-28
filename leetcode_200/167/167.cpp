#include "utils.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0,j=numbers.size()-1;i<j;){
            int sum=numbers[i]+numbers[j];
            if(sum==target)return {i+1,j+1};
            else if(sum<target)i++;
            else j--;
        }
        return {};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi numbers{2,7,11,15};
    int target=9;
    auto ans=sol.twoSum(numbers,target);
    DBGV(ans);

    system("pause");
    return 0;
}
