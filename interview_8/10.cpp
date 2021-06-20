#include "utils.h"

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size(),n=image[0].size();
        int old=image[sr][sc];
        if(old==newColor)return image;
        queue<pair<int,int>>Q;
        image[sr][sc]=newColor;
        Q.emplace(sr,sc);
        while(Q.size()){
            auto [i,j]=Q.front();
            Q.pop();
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID&&image[ii][jj]==old){
                    image[ii][jj]=newColor;
                    Q.emplace(ii,jj);
                }
            }
        }
        return image;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi image=makevvi("[[1,1,1],[1,1,0],[1,0,1]]");
    int sr=1;
    int sc=1;
    int newColor=2;
    auto ans=sol.floodFill(image,se,sc,newColor);
    DBGVV(ans);

    system("pause");
    return 0;
}
