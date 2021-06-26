#include "utils.h"

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<bool> gotit(n,0);
        queue<int>Q;
        int ans=0;
        for(int a:initialBoxes){
            gotit[a]=true;
            if(status[a])Q.push(a);
        }
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            ans+=candies[p];
            for(int k:keys[p]){
                if(!status[k]){
                    status[k]=1;
                    if(gotit[k])Q.push(k);
                }
            }
            for(int a:containedBoxes[p]){
                if(!gotit[a]){
                    gotit[a]=true;
                    if(status[a])Q.push(a);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    

    system("pause");
    return 0;
}
