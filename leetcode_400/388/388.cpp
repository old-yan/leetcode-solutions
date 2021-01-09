#include "utils.h"

class Solution {
public:
    int lengthLongestPath(string input) {
        stack<pair<int,int>>S;
        int ans=0;
        for(int i=0,j;i<input.size();i=j+1){
            int level=0;
            for(j=i;input[j]=='\t';j++)level++;
            bool have_dot=false;
            while(input[j]&&input[j]!='\n'){
                if(input[j++]=='.')have_dot=true;
            }
            while(S.size()&&S.top().first>=level)S.pop();
            if(S.empty()){
                S.push(make_pair(level,j-i-level));
            }
            else{
                S.push(make_pair(level,j-i-level+S.top().second+1));
            }
            if(have_dot)chmax(ans,S.top().second);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string input="dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    auto ans=sol.lengthLongestPath(input);
    DBG(ans);

    system("pause");
    return 0;
}
