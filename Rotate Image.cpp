/*两次变化就可以了，第一次左右交换位置，第二次左上和右下交位置*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        rotate_helper(matrix, 0, matrix.size()-1);
    }
    void swap(int &a, int &b){
        int t=a;
        a=b;
        b=t;
    }
    void rotate_helper(vector<vector<int>> &matrix, int s,int e){
        if(s==e)
            return;
        if(s+1==e){
            swap(matrix[s][s], matrix[s][s+1]);
            swap(matrix[s+1][s], matrix[s+1][s+1]);
            swap(matrix[s][s], matrix[e][e]);
            return;
        }
        rotate_helper(matrix, s+1, e-1);
        //左右调换
        int p=s,q=e;
        while(p<=q){
            swap(matrix[s][p], matrix[s][q]);
            swap(matrix[e][p], matrix[e][q]);
            p++;
            q--;
        }
        for(int i=s+1;i<=e-1;i++){
            swap(matrix[i][s], matrix[i][e]);
        }
        //斜调换
        
        for(int k=s+1;k<=e;k++){
            swap(matrix[k][e], matrix[s][s+e-k]);
        }
        for(int k=s+1;k<=e-1;k++){
            swap(matrix[e][k], matrix[s+e-k][s]);
        }
        return;
    }
};