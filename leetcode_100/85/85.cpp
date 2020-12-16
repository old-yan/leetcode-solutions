#include "utils.h"

class Solution {
    int n;
    int left[200],right[200];
    stack<int>S;
    int largestRectangleArea(int heights[]) {
        REP(i,n){
            while(S.size()&&heights[S.top()]>=heights[i]){
                right[S.top()]=i-S.top()-1;
                S.pop();
            }
            if(S.empty())left[i]=i;
            else left[i]=i-S.top()-1;
            S.push(i);
        }
        while(S.size()){
            right[S.top()]=n-S.top()-1;
            S.pop();
        }
        int ans=0;
        REP(i,n)chmax(ans,heights[i]*(1+left[i]+right[i]));
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(!m)return 0;
        n=matrix[0].size();
        int heights[n];
        int ans=0;
        REP(i,m){
            REP(j,n){
                if(!i)heights[j]=matrix[i][j]=='1';
                else{
                    if(matrix[i][j]=='1')heights[j]++;
                    else heights[j]=0;
                }
            }
            chmax(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};


int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>matrix{
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    auto ans=sol.maximalRectangle(matrix);
    DBG(ans);

    system("pause");
    return 0;
}
