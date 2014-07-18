class Solution {
public:
    /*从后往前比，不新建数组*/
    void merge(int A[], int m, int B[], int n) {
        int index = m+n-1;
        m--;
        n--;
        while(m!=-1&&n!=-1){
            if(A[m]>B[n]){
                A[index--]=A[m--];
            }else{
                A[index--]=B[n--];
            }
        }
        if(m==-1){
            for(int i=n;i>=0;i--)
                A[index--]=B[i];
        }
        if(n==-1){
            for(int i=m;i>=0;i--)
                A[index--]=A[i];
        }
    }
};