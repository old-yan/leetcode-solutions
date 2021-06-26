#include "utils.h"

class Solution {
public:
    int findString(vector<string>& words, string s) {
        int low=0,high=words.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            while(mid>=low&&words[mid].empty())mid--;
            if(mid<low)low=(low+high)/2+1;
            else if(words[mid]>=s)high=mid;
            else low=mid+1;
        }
        return words[low]==s?low:-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""};
    string s="ta";
    auto ans=sol.findString(words,s);
    DBG(ans);

    system("pause");
    return 0;
}
