#include "utils.h"

class Solution {
public:
    //先用字典对字符串出现次数进行计数，然后找出出现一次的就可以了
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>count_dict;
        for(auto&s:arr)count_dict[s]++;
        vector<string>v;
        for(auto&s:arr){
            if(count_dict[s]==1){
                v.push_back(s);
            }
        }
        return v.size()>=k?v[k-1]:"";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>arr{"d","b","c","b","c","a"};
    int k=2;
    auto ans=sol.kthDistinct(arr,k);
    DBG(ans);

    system("pause");
    return 0;
}