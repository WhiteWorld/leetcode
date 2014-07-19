class Solution {
public:
    /*简单递归*/
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        vector<int> row;
        if(numRows == 0)
            return result;
        if(numRows == 1){
            row.push_back(1);
            result.push_back(row);
            return result;
        }
        result = generate(numRows-1);
        vector<int> last_row = result[numRows-2];
        row.push_back(1);
        for(int i=1;i<last_row.size();i++)
            row.push_back(last_row[i]+last_row[i-1]);
        row.push_back(1);
        result.push_back(row);
        return result;
    }
};