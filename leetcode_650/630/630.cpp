#include "utils.h"

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        for(auto&A:courses){
            A.emplace_back(A[1]-A[0]);
        }
        auto comp=[](){};
        priority_queue<int,vi,decltype(comp)>Q(comp);
        unordered_map<int,int>M;
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi courses{
        {100,200},{200,1300},{1000,1250},{2000,3200}
    };
    auto ans=sol.scheduleCourse(courses);
    DBG(ans);

    system("pause");
    return 0;
}
