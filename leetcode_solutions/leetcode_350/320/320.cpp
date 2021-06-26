#include "utils.h"

class Solution {
    string s1,s2;
    string fun(string&s,int k){
        string res;
        REP(i,s.size()){
            while(res.size()&&res.size()+s.size()-i>k&&res.back()<s[i])res.pop_back();
            if(res.size()<k)res.pb(s[i]);
        }
        return res;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        for(int a:nums1)s1+='0'+a;
        for(int a:nums2)s2+='0'+a;
        string ans_string;
        REP(i,k+1){
            if(i>nums1.size())break;
            if(k-i>nums2.size())continue;
            auto v1=fun(s1,i);
            auto v2=fun(s2,k-i);
            string v;
            int i1=0,i2=0;
            while(i1<v1.size()&&i2<v2.size()){
                if(strcmp(&v1[i1],&v2[i2])>=0)v.pb(v1[i1++]);
                else v.pb(v2[i2++]);
            }
            v+=v1.substr(i1,v1.size()-i1);
            v+=v2.substr(i2,v2.size()-i2);
            chmax(ans_string,v);
        }
        vi ans;
        for(char c:ans_string)ans.pb(c-'0');
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{6,7};
    vi nums2{};
    int k=2;
    auto ans=sol.maxNumber(nums1,nums2,k);
    DBGV(ans);

    system("pause");
    return 0;
}
