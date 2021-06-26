#include "utils.h"

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        for(string&l:logs){
            if(l=="../"){
                if(depth)depth--;
            }
            else if(l!="./"){
                depth++;
            }
        }
        return depth;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>logs{"d1/","d2/","../","d21/","./"};
    auto ans=sol.minOperations(logs);
    DBG(ans);

    system("pause");
    return 0;
}
