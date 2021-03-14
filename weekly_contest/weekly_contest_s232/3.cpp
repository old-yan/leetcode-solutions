#include "utils.h"

class Solution {
public:
    //对学生进行逐个决策，每次都把当前学生派给能产生最大通过率变化得班级
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        //ratio数组可以理解为导数，总之就是多一个学生比当前多出的通过率，笔算一下即可
        double ratio[n];
        for(int i=0;i<n;i++){
            long long a=classes[i][0],b=classes[i][1];
            ratio[i]=(double(b-a))/double(b*(b+1));
        }
        //将所有班级送入优先级队列，谁的ratio大，就把当前学生送到他们班
        auto comp=[&](int x,int y){return ratio[x]<ratio[y];};
        priority_queue<int,vector<int>,decltype(comp)>Q(comp);
        for(int i=0;i<n;i++)Q.emplace(i);
        while(extraStudents--){
            auto p=Q.top();
            Q.pop();
            //这个班增员之后，还可以继续增员。但是要重新计算导数
            classes[p][0]++;
            classes[p][1]++;
            long long a=classes[p][0],b=classes[p][1];
            ratio[p]=(double(b-a))/double(b*(b+1));
            Q.emplace(p);
        }
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=double(classes[i][0])/classes[i][1];
        }
        return sum/n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi classes=makevvi("[[1,2],[3,5],[2,2]]");
    int extraStudents=2;
    auto ans=sol.maxAverageRatio(classes,extraStudents);
    DBG(ans);

    system("pause");
    return 0;
}
