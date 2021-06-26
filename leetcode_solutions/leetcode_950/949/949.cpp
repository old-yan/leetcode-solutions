#include "utils.h"

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string ans;
        for(int i=0;i<24;i++){
            next_permutation(ALL(arr));
            if(arr[0]*10+arr[1]<24&&arr[2]*10+arr[3]<60){
                string s(5,':');
                s[0]=arr[0]+'0';
                s[1]=arr[1]+'0';
                s[3]=arr[2]+'0';
                s[4]=arr[3]+'0';
                chmax(ans,s);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,3,4};
    auto ans=sol.largestTimeFromDigits(arr);
    DBG(ans);

    system("pause");
    return 0;
}
