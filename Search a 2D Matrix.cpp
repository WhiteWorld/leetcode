class Solution {
public:
    /*一般解*/
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()==0)
            return false;
        int row;
        for(row=0;row<matrix.size();row++){
            if(matrix[row][0]>target)
                break;
        }
        if(row==0)
            return false;
        for(int i=0;i<matrix[row-1].size();i++){
            if(matrix[row-1][i]==target)
                return true;
            if(matrix[row-1][i]>target)
                return false;
        }
    }
    /*二分法,对行和列分别进行二分检索，略*/
    
};