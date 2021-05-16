#include "utils.h"

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int a=0,b=0;
        for(int each:students){
            a+=each==0;
            b+=each==1;
        }
        for(int each:sandwiches){
            if(each==0){
                if(a)a--;
                else break;
            }
            else{
                if(b)b--;
                else break;
            }
        }
        return a+b;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi students{1,1,0,0};
    vi sandwiches{0,1,0,1};
    auto ans=sol.countStudents(students,sandwiches);
    DBG(ans);

    system("pause");
    return 0;
}
