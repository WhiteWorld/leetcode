class Solution {
public:
    
    /*这样会TLE错误 */
    int mygetc(int a, int b){
        if(b==0)
            return 1;
        if(b==1)
            return a;
        if(a==b)
            return 1;
        return mygetc(a-1, b-1)+mygetc(a-1,b);
    }
    int uniquePaths1(int m, int n) {
        m--;
        n--;
        return mygetc(m+n,m);
    }
    /*动态规划解决*/
    int uniquePaths(int m, int n) {
        vector<int> map(m+1, 0);
        map[1]=1;
        for(int i=0; i<n; i++){
            for(int j=1; j<=m; j++)
                map[j] = map[j-1]+map[j];
        }
        return map[m];
    }

};