class Solution {
public:
    /*依然动态规划*/
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid.size();
        if(n==0)
            return 0;
        int m = obstacleGrid[0].size();
        if(m == 0)
            return 0;
        return helper(m, n, obstacleGrid);
    }
    int helper(int m, int n, vector<vector<int> > &grid) {
        vector<int> map(m+1, 0);
        for(int i=0; i<n; i++){
            if(i==0){
                if(grid[i][0]==1)
                    map[0]=0;
                else
                    map[0]=1;
            }else{
                if(grid[i-1][0]==1)
                    map[0]=0;
            }
            if(grid[i][0])
                map[0]=0;
            for(int j=1; j<m; j++){
                if(i==0){
                    if(grid[i][j-1]==1)
                        map[j]=0;
                    else
                        map[j]=map[j-1];
                }else{
                    if(grid[i-1][j]==1&&grid[i][j-1]==1)
                        map[j] = 0;
                    else if(grid[i-1][j]==1)
                        map[j] = map[j-1];
                    else if(grid[i][j-1]==1)
                        ;//map[i][j] = map[i-1][j];
                    else
                        map[j] = map[j-1]+map[j];
                }
                if(grid[i][j]==1)
                    map[j]=0;
            }
            
        }
        return map[m-1];
    }
};