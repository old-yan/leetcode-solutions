#include "utils.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i,j;
        vector<string>ans;
        for(i=j=0;i<words.size();){
            int curlen=words[i].size();
            for(j=i+1;j<words.size();j++){
                if(curlen+1+words[j].size()>maxWidth)break;
                curlen+=1+words[j].size();
            }
            if(j==i+1){
                while(words[i].size()<maxWidth)words[i]+=' ';
                ans.pb(words[i++]);
            }
            else if(j==words.size()){
                string temp=words[i];
                while(++i<j)temp+=' '+words[i];
                while(temp.size()<maxWidth)temp+=' ';
                ans.pb(temp);
            }
            else{
                curlen-=(j-i-1);
                int blank=(maxWidth-curlen)/(j-i-1);
                int extra=maxWidth-curlen-blank*(j-i-1);
                string temp=words[i];
                while(++i<j){
                    if(extra){
                        temp+=' ';
                        extra--;
                    }
                    REP(i,blank)temp+=' ';
                    temp+=words[i];
                }
                ans.pb(temp);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"What","must","be","acknowledgment","shall","be"};
    int maxWidth=16;
    auto ans=sol.fullJustify(words,maxWidth);
    DBGV(ans);

    system("pause");
    return 0;
}
