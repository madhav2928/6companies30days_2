#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265
class Solution {
public:
    // bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    //     // // double one = (double)(p1[1]-p2[1])/(p1[0]-p2[0]);
    //     // // double oneval = (atan(one)* 180) / PI;
    //     // // double two = (double)(p3[1]-p4[1])/(p3[0]-p4[0]);
    //     // // double twoval = (atan(one)* 180) / PI;
    //     // double oneval =(double)(atan2((p1[1]-p2[1]),(p1[0]-p2[0]))*180)/PI;
    //     // double twoval = (double)(atan2((p3[1]-p4[1]),(p3[0]-p4[0]))*180)/PI;
    //     // cout<<oneval<<endl<<twoval<<endl;
    //     // // if(one*two==-1)
    //     // // {
    //     // //     return true;
    //     // // }
    //     // double one = abs(oneval-twoval);
    //     // double two = abs(oneval+twoval);
    //     // cout<<abs(oneval-twoval)<<endl<<abs(oneval+twoval)<<endl;
    //     // if((one==90.00) || (two==90.00))
    //     // {
    //     //     return true;
    //     // }
    //     // return false;
        
    // }

    int distance( vector < int > v1 , vector < int > v2){
        return (v1[0]- v2[0])* (v1[0]- v2[0]) + (v1[1]- v2[1]) * (v1[1]- v2[1]);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set < int > st ;

        // calculate all possible values as " The input is not given in any order "
        st.insert(distance(p1 , p2));
        st.insert(distance(p1 , p3));
        st.insert(distance(p1 , p4));
        st.insert(distance(p2 , p3));
        st.insert(distance(p2 , p4));
        st.insert(distance(p3 , p4));


        // valid square :) 
        return st.size()==2 and st.find(0)==st.end();
    }
};