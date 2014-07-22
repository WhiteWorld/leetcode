/*简单推算*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1)
            return n;
        int ret=0;
        int last=A[0]-1;
        bool flag=true;
        for(int i=0;i<n;i++)
            if(A[i]!=last||(A[i]==last&&flag)){
                if(A[i]==last)
                    flag = false;
                else
                    flag = true;
                last=A[i];
                A[ret]=A[i];
                ret++;
            }
        return ret;
    }
};