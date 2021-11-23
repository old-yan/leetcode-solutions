#include "utils.h"

class Solution {
public:
    //本题为模拟题，将每一条斜线的字符挨个收集起来，然后把末尾空格去掉即可
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText.empty())return "";
        int m=rows,n=encodedText.size()/m;
        //这里用一个宏定义，实现二维坐标(i,j)取字符，这样就不用写静态数组了
        #define a(i,j) encodedText[(i)*n+(j)]
        string ans;
        for(int start_col=0;start_col<n;start_col++){
            int i=0,j=start_col;
            while(i<m and j<n){
                ans+=a(i,j);
                i++,j++;
            }
        }
        while(ans.back()==' ')ans.pop_back();
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string encodedText="ch   ie   pr";
    int rows=3;
    auto ans=sol.decodeCiphertext(encodedText,rows);
    DBG(ans);

    system("pause");
    return 0;
}