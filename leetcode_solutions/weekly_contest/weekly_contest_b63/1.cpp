#include "utils.h"

class Solution {
public:
    //首先确定一条性质：靠前的学生移动到靠前的座位，靠后的学生移动到靠后的座位，这样产生的移动代价最小
    //将座位和学生当前位置各自排序，然后计算每个学生和对应座位之间的差距
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int ans=0;
        sort(ALL(seats));
        sort(ALL(students));
        for(int i=0;i<seats.size();i++){
            ans+=abs(seats[i]-students[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi seats{4,1,5,9};
    vi students{1,3,2,6};
    auto ans=sol.minMovesToSeat(seats,students);
    DBG(ans);

    system("pause");
    return 0;
}