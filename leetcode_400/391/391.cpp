#include "utils.h"

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int top=INT_MIN,bottom=INT_MAX,left=INT_MAX,right=INT_MIN;
        unordered_map<int,unordered_map<int,int>>M;
        for(auto&A:rectangles){
            int x1=A[0],y1=A[1],x2=A[2],y2=A[3];
            if(M[x1][y1]&1)return false;
            M[x1][y1]|=1;
            if(M[x1][y2]&8)return false;
            M[x1][y2]|=8;
            if(M[x2][y1]&2)return false;
            M[x2][y1]|=2;
            if(M[x2][y2]&4)return false;
            M[x2][y2]|=4;
            chmax(top,y2);
            chmin(bottom,y1);
            chmax(right,x2);
            chmin(left,x1);
        }
        for(auto&A:M){
            for(auto&a:A.second){
                if(A.first==left){
                    if(a.first==top){
                        if(a.second!=8)return false;
                    }
                    else if(a.first==bottom){
                        if(a.second!=1)return false;
                    }
                    else if(a.second!=9)return false;
                }
                else if(A.first==right){
                    if(a.first==top){
                        if(a.second!=4)return false;
                    }
                    else if(a.first==bottom){
                        if(a.second!=2)return false;
                    }
                    else if(a.second!=6)return false;
                }
                else{
                    if(a.first==top){
                        if(a.second!=12)return false;
                    }
                    else if(a.first==bottom){
                        if(a.second!=3)return false;
                    }
                    else if(a.second%3)return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi rectangles{
        {1,1,3,3},
        {3,1,4,2},
        {3,2,4,4},
        {1,3,2,4},
        {2,3,3,4}
    };
    auto ans=sol.isRectangleCover(rectangles);
    DBG(ans);

    system("pause");
    return 0;
}
