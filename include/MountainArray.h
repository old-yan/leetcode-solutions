#include <iostream>
#include <vector>
using namespace std;

class MountainArray {
    vector<int> arr;
    int life;
public:
    MountainArray(const vector<int>&_arr):arr(_arr),life(100){}
    int get(int index){
        if(life--<=0){
            cout<<"no life\n";
            system("pause");
        }
        return arr[index];
    }
    int length(){
        return arr.size();
    }
};