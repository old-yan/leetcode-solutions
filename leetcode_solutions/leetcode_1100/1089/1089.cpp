#include "utils.h"

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i=0,j=0;
        while(true){
            if(arr[i])j++;
            else j+=2;
            if(j>=arr.size())break;
            i++;
        }
        while(i>=0){
            if(arr[i]){
                arr[--j]=arr[i];
            }
            else{
                if(j--<=arr.size())arr[j]=0;
                arr[--j]=0;
            }
            i--;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,0,2,3,0,4,5,0};
    sol.duplicateZeros(arr);
    DBGV(arr);

    system("pause");
    return 0;
}
