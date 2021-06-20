#include "utils.h"

class Solution {
public:
    int halfQuestions(vector<int>& questions) {
        sort(ALL(questions));
        vi v;
        for(int i=0,j;i<questions.size();i=j){
            for(j=i+1;j<questions.size()&&questions[j]==questions[i];j++);
            v.pb(j-i);
        }
        sort(ALLR(v));
        int cursum=0,curans=0;
        for(int a:v){
            cursum+=a;
            curans++;
            if(cursum>=questions.size()/2){
                break;
            }
        }
        return curans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi queries{2,1,6,2};
    auto ans=sol.halfQuestions(queries);
    DBG(ans);

    system("pause");
    return 0;
}
