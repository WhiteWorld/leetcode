class Solution {
public:
    /*从底网上递推*/
    int minimumTotal(vector<vector<int> > &triangle) {
        int result;
        int row = triangle.size();
        if(row == 0)
            return 0;
        if(row == 1){
            if(triangle[0].size()==0)
                return 0;
            int min=triangle[0][0];
            for(int i=0;i<triangle[0].size();i++)
                if(triangle[0][i]<min)
                    min = triangle[0][i];
            return min;
        }
        vector<int> v = triangle[row-1];
        for(int i=row-2;i>=0;i--)
            for(int j=0;j<=i+1;j++)
                v[j]=triangle[i][j]+min(v[j], v[j+1]);
        return v[0];
    }
};