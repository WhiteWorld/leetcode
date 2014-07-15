/*全部异或*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int len=sizeof(A);
        int result=A[0];
        for(int i=1;i<len;i++)
            result^=A[i];
        return result;
    }
};