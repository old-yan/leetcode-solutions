#include "utils.h"

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size(),n=image[0].size();
        int oldColor=image[sr][sc];
        if(oldColor==newColor)return image;
        queue<pair<int,int>>Q;
        image[sr][sc]=newColor;
        Q.emplace(sr,sc);
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            REP(k,4){
                int ii=p.first+di[k],jj=p.second+dj[k];
                if(VALID&&image[ii][jj]==oldColor){
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
    auto ans=sol.floodFill(image,sr,sc,newColor);
    DBGVV(ans);

    system("pause");
    return 0;
}
