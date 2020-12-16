#include "utils.h"

class Solution {
    void getnext(string&needle,vector<int>&next){
        for(int i=0,j=-1;i<needle.size();i++){
            if(!i)next[i]=j;
            else{
                while(j>=0&&needle[i-1]!=needle[j])j=next[j];
                next[i]=++j>=0&&needle[i]==needle[j]?next[j]:j;
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        //return haystack.find(needle);
        vector<int>next(needle.size(),-2);
        getnext(needle,next);
        for(int i=0,j=0;;){
            if(j==needle.size())return i-j;
            if(i==haystack.size())break;
            if(j<0||haystack[i]==needle[j]){
                i++,j++;
            }
            else{
                j=next[j];
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string haystack="hello";
    string needle="ll";
    auto ans=sol.strStr(haystack,needle);
    DBG(ans);

    system("pause");
    return 0;
}
