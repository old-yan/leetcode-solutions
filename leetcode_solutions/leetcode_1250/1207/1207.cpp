#include "utils.h"

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(ALL(arr));
        auto next=next_different(arr);
        int cnt=0;
        unordered_set<int>S;
        for(int i=0;i<next.size();i=next[i]){
            S.insert(next[i]-i);
            cnt++;
        }
        return S.size()==cnt;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,2,1,1,3};
    auto ans=sol.uniqueOccurrences(arr);
    DBG(ans);

    system("pause");
    return 0;
}
