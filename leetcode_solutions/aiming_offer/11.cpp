#include "utils.h"

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.front()<numbers.back())return numbers.front();
        int low=0,high=numbers.size()-1;
        while(low<high){
            if(numbers[low]<numbers[high])return numbers[low];
            else if(numbers[low]>numbers[high]){
                int mid=(low+high)/2;
                if(numbers[mid]<=numbers[high])high=mid;
                else low=mid+1;
            }
            else{
                int val=numbers[low];
                while(low<high&&numbers[low]==val){
                    low++;
                }
                if(low==high)return val;
                else if(numbers[low]<val)return numbers[low];
                else continue;
            }
        }
        return numbers[low];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi numbers{3,4,5,1,2};
    auto ans=sol.minArray(numbers);
    DBG(ans);

    system("pause");
    return 0;
}
