#include "utils.h"

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>M;
        for(auto&A:paths){
            int first_space=A.find_first_of(' ',0);
            for(int i=first_space,j,k;i>=0;i=A.find_first_of(' ',k)){
                j=A.find_first_of('(',i);
                k=A.find_first_of(')',j);
                string content=A.substr(j+1,k-j-1);
                M[content].emplace_back(A.substr(0,first_space)+'/'+A.substr(i+1,j-i-1));
            }
        }
        vector<vector<string>>ans;
        for(auto&it:M){
            if(it.second.size()>=2){
                ans.emplace_back(move(it.second));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>paths{
        "root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"
    };
    auto ans=sol.findDuplicate(paths);
    DBGVV(ans);

    system("pause");
    return 0;
}
