#include "utils.h"

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        if(!n)return false;
        bool tested[n][2];
        bool visited[n];
        memset(tested,0,sizeof(tested));
        REP(i,n){
            if(nums[i]>0){
                tested[i][0]=true;
                if(!tested[i][1]){
                    stack<int>S;
                    bool failed=false;
                    memset(visited,0,sizeof(visited));
                    int j;
                    for(j=i;!visited[j];){
                        S.push(j);
                        visited[j]=true;
                        j=(j+nums[j])%n;
                        if(nums[j]<0||tested[j][1]){
                            failed=true;
                            break;
                        }
                    }
                    if(!failed&&S.top()!=j)return true;
                    while(S.size()){
                        tested[S.top()][1]=true;
                        S.pop();
                    }
                }
            }
            else{
                tested[i][1]=0;
                if(!tested[i][0]){
                    stack<int>S;
                    bool failed=false;
                    memset(visited,0,sizeof(visited));
                    int j;
                    for(j=i;!visited[j];){
                        S.push(j);
                        visited[j]=true;
                        j=(j+n*1000+nums[j])%n;
                        if(nums[j]>0||tested[j][0]){
                            failed=true;
                            break;
                        }
                    }
                    if(!failed&&S.top()!=j)return true;
                    while(S.size()){
                        tested[S.top()][0]=true;
                        S.pop();
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-1,-2,-3,-4,-5};
    auto ans=sol.circularArrayLoop(nums);
    DBG(ans);

    system("pause");
    return 0;
}
