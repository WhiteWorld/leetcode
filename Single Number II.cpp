class Solution {
public:
    /*判断数组中的数在一位上的和是否能被3整除*/
    int singleNumber(int A[], int n) {
        int result=0;
        for(int i=0;i<32;i++){
            int num=0;
            for(int j=0;j<n;j++)
                if((A[j]>>i)&1)
                    num++;
            result |= ((num%3)<<i);
        }
        return result;
    }
    /*没看懂*/
    int singleNumber1(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};