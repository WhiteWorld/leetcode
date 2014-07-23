/*从后往前加*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1);
        if(rowIndex == 0){
            result[0] = 1;
            return result;
        }
        if(rowIndex == 1){
            result[0] = 1;
            result[1] = 1;
            return result;
        }
        result[0] = 1;
        result[1] = 2;
        result[2] = 1;
        for(int i=3;i<=rowIndex;i++){
            result[i] = 1;
            for(int j=i-1;j>=1;j--)
                result[j] = result[j] + result[j-1];
        }
        return result;
    }
};