#include "utils.h"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int rest[128]={0};
        for(char c:tasks)rest[c]++;
        auto comp=[&](int x,int y){
            return rest[x]<rest[y];
        };
        priority_queue<int,vi,decltype(comp)>Q(comp);
        REP(i,26){
            if(rest['A'+i])Q.push('A'+i);
        }
        char c[tasks.size()*(n+1)];
        memset(c,0,sizeof(c));
        int resttask=tasks.size();
        int ans=0;
        for(int i=0;resttask;i++){
            if(i>n&&c[i-n-1]&&rest[c[i-n-1]])Q.push(c[i-n-1]);
            if(Q.size()){
                c[i]=Q.top();
                rest[c[i]]--;
                resttask--;
                Q.pop();
            }
            chmax(ans,i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<char>tasks{'A','A','A','B','B','B'};
    int n=2;
    auto ans=sol.leastInterval(tasks,n);
    DBG(ans);

    system("pause");
    return 0;
}
