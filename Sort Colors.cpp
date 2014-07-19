/*把0放在前面，2放在后面，1一定出现中间*/
class Solution {
public:
    void swap(int A[],int i1,int i2){
        int t = A[i1];
        A[i1] = A[i2];
        A[i2] = t;
    }
    void sortColors(int A[], int n) {
        if(n==1)
            return;
        int a=0,b=n-1;
        while(A[a]==0){
            a++;
            if(a == n)
                return;
        }
        for(int i=a;i<n;i++){
            if(A[i]==0){
                swap(A, a, i);
                while(A[a]==0){
                    a++;
                    if(a == n)
                        return;
                }
            }
        }
        while(A[b]==2){
            b--;
            if(b == -1)
                return;
        }
        for(int i=b;i>=a;i--)
            if(A[i]==2){
                swap(A, b, i);
                while(A[b]==2){
                    b--;
                    if(b == -1)
                        return;
                }
            }
        return;
    }
};