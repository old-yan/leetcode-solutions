#include "Heap.h"
#include "utils.h"

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int>M;
        for(int a:arr)M[a]++;
        if(M[0]%2)return false;
        M.erase(0);
        for(auto it=M.begin();it!=M.end();++it){
            if(it->first<0){
                if(it->first%2)return false;
                auto find=M.find(it->first/2);
                if(find->second<it->second)return false;
                find->second-=it->second;
                if(!find->second)M.erase(find);
            }
            else{
                auto find=M.find(it->first*2);
                if(find->second<it->second)return false;
                find->second-=it->second;
                if(!find->second)M.erase(find);
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{}

    system("pause");
    return 0;
}
