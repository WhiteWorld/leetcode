class Solution {
public:
    /*一次扫描即可*/
    bool canJump(int A[], int n) {
        if(n==1)
            return true;
        int last=A[0];
        for(int i=0;i<n-2;i++){
            if(last==0)
                return false;
            if(last-1>A[i+1])
                last = last - 1;
            else
                last = A[i+1];
        }
        if(last>=1)
            return true;
        return false;
    }
};