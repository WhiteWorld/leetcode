class Solution {
public:
    /*找规律，动态规划*/
    int climbStairs(int n) {
        if(n<3)
            return n;
        int a,b;
        a=1;
        b=2;
        for(int i=3;i<=n;i++){
            int c;
            c = b;
            b = b + a;
            a = c;
        }
        return b;
    }
};