#include "utils.h"

class Solution {
public:
    //这道题数据范围很小，所以可以暴力穷举
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m=students.size(),n=students[0].size();
        //先预处理出 所有学生和辅导员 的掩膜
        int students_mask[m],mentor_mask[m];
        {
            for(int i=0;i<m;i++){
                students_mask[i]=0;
                for(int j=0;j<n;j++)students_mask[i]|=students[i][j]<<j;
            }
            for(int i=0;i<m;i++){
                mentor_mask[i]=0;
                for(int j=0;j<n;j++)mentor_mask[i]|=mentors[i][j]<<j;
            }
        }
        //让学生按照 1~m 的顺序站好，固定位置
        //使用 next_permutation 来穷举 导员的 排列
        vector<int>mentor_sequence(m);
        for(int i=0;i<m;i++)mentor_sequence[i]=i;
        int ans=0;
        do{
            int score=0;
            for(int i=0;i<m;i++){
                score+=n-__builtin_popcount(students_mask[i]^mentor_mask[mentor_sequence[i]]);
            }
            ans=max(ans,score);
        }while(next_permutation(mentor_sequence.begin(),mentor_sequence.end()));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi students=makevvi("[[1,1,0],[1,0,1],[0,0,1]]");
    vvi mentors=makevvi("[[1,0,0],[0,0,1],[1,1,0]]");
    auto ans=sol.maxCompatibilitySum(students,mentors);
    DBG(ans);

    system("pause");
    return 0;
}
