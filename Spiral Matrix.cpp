/*简单递归*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int row = matrix.size();
        if(row == 0)
            return result;
        int col = matrix[0].size();
        if(col == 0)
            return result;
        return spiralOrderHelper(matrix, 1);
    }
    vector<int> spiralOrderHelper(vector<vector<int> > &matrix, int n){
        vector<int> result;
        int row = matrix.size();
        int col = matrix[0].size();
        if(n-1 > row-n)
            return result;
        else if(n-1 == row-n){
            for(int i=n-1;i<=col-n;i++)
                result.push_back(matrix[n-1][i]);
            return result;
        }
        if(n-1 > col-n)
            return result;
        else if(n-1 == col-n){
            for(int i=n-1;i<=row-n;i++)
                result.push_back(matrix[i][n-1]);
            return result;
        }
        result = spiralOrderHelper(matrix, n+1);
        vector<int> v;
        
        for(int i=n-1;i<=col-n;i++)
            v.push_back(matrix[n-1][i]);
        for(int i=n;i<=row-n;i++)
            v.push_back(matrix[i][col-n]);
        for(int i=col-n-1;i>=n-1;i--)
            v.push_back(matrix[row-n][i]);
        for(int i=row-n-1;i>=n;i--)
            v.push_back(matrix[i][n-1]);
        result.insert(result.begin(), v.begin(), v.end());
        return result;
    }
};