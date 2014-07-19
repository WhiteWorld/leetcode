class Solution {
public:
    /*简单递归*/
    int pow2(int n){
        if(n==0)
            return 1;
        if(n==1)
            return 2;
        return 2*pow2(n-1);
    }
    vector<int> grayCode(int n) {
        vector<int> v;
        if(n==0){
            v.push_back(0);
            return v;
        }
        if(n == 1){
            v.push_back(0);
            v.push_back(1);
            return v;
        }
        v = grayCode(n-1);
        for(int i=v.size()-1;i>=0;i--)
            v.push_back(v[i]+pow2(n-1));
        return v;
    }
};