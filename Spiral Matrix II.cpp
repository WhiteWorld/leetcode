/*简单递归*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        if(n==0)
            return matrix;
        generateMatrixHelper(matrix, 1,1, n);
        return matrix;
    }
    void generateMatrixHelper(vector<vector<int> > &matrix, int m,int start, int n){
        if(m-1 > n-m)
            return;
        else if(m-1 == n-m){
            matrix[m-1][m-1] = start;
            return;
        }
        int s=start;
        for(int i=m-1;i<=n-m;i++)
            matrix[m-1][i]=s++;
        for(int i=m;i<=n-m;i++)
            matrix[i][n-m]=s++;
        for(int i=n-m-1;i>=m-1;i--)
            matrix[n-m][i]=s++;
        for(int i=n-m-1;i>=m;i--)
            matrix[i][m-1]=s++;
        generateMatrixHelper(matrix, m+1, s, n);
    }
};