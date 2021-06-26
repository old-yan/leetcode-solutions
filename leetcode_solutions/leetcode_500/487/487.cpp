#include "utils.h"

class Solution {
    unordered_map<char,int>M;
    string material;
    int num[128]={0};
    int ans=INT_MAX;
    void fun(string&L,int curstep){
        if(L.empty()){
            ans=curstep;
        }
        else{
            for(char c:material){
                if(!num[c])continue;
                num[c]--;
                for(int i=0;i<=L.size();){
                    if(curstep+1>=ans)break;
                    string L2=L;
                    L2.insert(L2.begin()+i,c);
                    int idx=i;
                    while(idx<L2.size()){
                        int start;
                        for(start=idx;start>0&&L2[start-1]==L2[idx];start--);
                        int end;
                        for(end=idx+1;end<L2.size()&&L2[end]==L2[idx];end++);
                        if(end-start>=3){
                            L2.erase(L2.begin()+start,L2.begin()+end);
                            idx=start;
                        }
                        else break;
                    }
                    fun(L2,curstep+1);
                    if(i==L.size())break;
                    if(L[i]==c){
                        while(++i<L.size()&&L[i-1]==c);
                        if(L[i-1]==c)break;
                    }
                    else i++;
                }
                num[c]++;
            }
        }
    }
public:
    int findMinStep(string board, string hand) {
        for(char c:hand){
            if(!M.count(c)){
                M[c]=M.size();
                material+=c;
            }
        }
        for(char c:hand)num[c]++;
        fun(board,0);
        return ans==INT_MAX?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string board="WWRRBBWW";
    string band="WRBRW";
    auto ans=sol.findMinStep(board,band);
    DBG(ans);

    system("pause");
    return 0;
}
