class Solution {
public:
    /* with extra space..*/
    void setZeroes1(vector<vector<int> > &matrix) {
        stack<int> s;
        int row = matrix.size();
        if(row == 0)
            return;
        int col = matrix[0].size();
        if(col == 0)
            return;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(matrix[i][j]==0){
                    s.push(j);
                    s.push(i);
                }
        while(!s.empty()){
            int r = s.top();
            s.pop();
            int c = s.top();
            s.pop();
            std::fill(matrix[r].begin(), matrix[r].end(), 0);
            for(int i=0;i<row;i++)
                matrix[i][c]=0;
        }
    }
    /* without extra space */
    void setZeroes(vector<vector<int> > &matrix) {
        int rownum = matrix.size();
        if (rownum == 0)  return;
        int colnum = matrix[0].size();
        if (colnum == 0)  return;
    
        bool hasZeroFirstRow = false, hasZeroFirstColumn = false;
    
        // Does first row have zero?
        for (int j = 0; j < colnum; ++j) {
            if (matrix[0][j] == 0) {
                hasZeroFirstRow = true;
                break;
            }
        }
    
        // Does first column have zero?
        for (int i = 0; i < rownum; ++i) {
            if (matrix[i][0] == 0) {
                hasZeroFirstColumn = true;
                break;
            }
        }
    
        // find zeroes and store the info in first row and column
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
    
        // set zeroes except the first row and column
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
            }
        }
    
        // set zeroes for first row and column if needed
        if (hasZeroFirstRow) {
            for (int j = 0; j < colnum; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (hasZeroFirstColumn) {
            for (int i = 0; i < rownum; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
    
    
};