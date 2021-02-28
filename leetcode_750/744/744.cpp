#include "utils.h"

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back()==target)return letters.front();
        int low=0,high=letters.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(letters[mid]>target)high=mid;
            else low=mid+1;
        }
        return letters[low];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<char>letters{'c','f','j'};
    char target='a';
    auto ans=sol.nextGreatestLetter(letters,target);
    DBG(ans);

    system("pause");
    return 0;
}
