class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();
        if(col == 0)
            return 0;
        vector <vector<int> > f(row, vector<int>(col));//N行M列,动态的
        f[0][0] = grid[0][0];
        for(int j=1;j<col;j++)
            f[0][j] = grid[0][j] + f[0][j-1];
        for(int i=1; i<row; i++)
            f[i][0] = grid[i][0] + f[i-1][0];
        for(int i=1;i<row;i++)
            for(int j=1;j<col;j++)
                f[i][j]=min(f[i-1][j], f[i][j-1])+grid[i][j];
        return f[row-1][col-1];
        // return minPathSumHelper(grid, row-1, col-1);
    }
    /*递归, TLE。。*/
    int minPathSumHelper(vector<vector<int>> &grid, int row, int col){
        int result = 0;
        if(row == 0){
            for(int i=0;i<=col;i++)
                result+=grid[0][i];
            return result;
        }
        if(col == 0){
            for(int i=0;i<=row;i++)
                result+=grid[i][0];
            return result;     
        }
        return min(minPathSumHelper(grid, row-1,col), minPathSumHelper(grid, row, col-1));
    }
    
};