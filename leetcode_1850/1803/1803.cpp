#include "Trie.h"
#include "utils.h"

struct mybitrie:public BiTrie<14>{
    int low,high;
    mybitrie(int _low,int _high):BiTrie<14>(),low(_low),high(_high){}
    void insert(int num){
        int cur=0;
        for(int i=14;i>=0;i--){
            data[cur][2]++;
            int&next=data[cur][num>>i&1];
            if(!next)next=used++;
            cur=next;
        }
        data[cur][2]++;
    }
    int dfs(int a,int cur,int i,int curxor){
        if(curxor>>i<low>>i||curxor>>i>high>>i)return 0;
        if(curxor>>i>low>>i&&curxor>>i<high>>i)return data[cur][2];
        if(!i)return data[cur][2];
        int res=0;
        if(data[cur][0])
            res+=dfs(a,data[cur][0],i-1,curxor+(a&(1<<(i-1))));
        if(data[cur][1])
            res+=dfs(a,data[cur][1],i-1,curxor+(~a&(1<<(i-1))));
        return res;
    }
    int find(int a){
        return dfs(a,0,15,0);
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        ll ans=0;
        mybitrie T(low,high);
        for(int a:nums){
            ans+=T.find(a);
            T.insert(a);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,4,2,7};
    int low=2;
    int high=6;
    auto ans=sol.countPairs(nums,low,high);
    DBG(ans);

    system("pause");
    return 0;
}
