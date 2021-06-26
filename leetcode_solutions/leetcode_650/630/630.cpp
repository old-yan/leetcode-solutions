#include "utils.h"

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(ALL(courses),[&](vi&x,vi&y)->bool{return x[1]<y[1];});
        int curday=0;
        int curcourse=0;
        priority_queue<int>Q;
        REP(i,courses.size()){
            int day=courses[i][0],ddl=courses[i][1];
            if(ddl-curday>=day){
                Q.push(day);
                curday+=day;
                curcourse++;
            }
            else if(Q.size()&&Q.top()>day){
                curday-=Q.top();
                curday+=day;
                Q.pop();
                Q.push(day);
            }
        }
        return curcourse;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi courses{
        {5,5},{4,6},{2,6}
    };
    auto ans=sol.scheduleCourse(courses);
    DBG(ans);

    system("pause");
    return 0;
}
