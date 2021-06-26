#include "utils.h"

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(char&c:paragraph)c=tolower(c);
        unordered_map<string,int>M;
        unordered_set<string>ban(ALL(banned));
        string ans;
        int ansnum=0;
        for(int i=0,j;paragraph[i];){
            for(j=i+1;isalpha(paragraph[j]);j++);
            string s=paragraph.substr(i,j-i);
            if(!ban.count(s)&&chmax(ansnum,++M[s])){
                ans=s;
            }
            for(i=j;paragraph[i]&&!isalpha(paragraph[i]);i++);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string paragraph="Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string>banned{"hit"};
    auto ans=sol.mostCommonWord(paragraph,banned);
    DBG(ans);

    system("pause");
    return 0;
}
