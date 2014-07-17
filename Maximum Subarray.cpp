class Solution {
public:
    /*O(n)动态规划*/
    int maxSubArray1(int A[], int n) {
        int m = A[n-1];
        int max = m;
        for(int i=n-1;i>=1;i--){
            if(m < 0)
                m = A[i-1];
            else
                m = m + A[i-1];
            if(m > max)
                max = m;
        }
        return max;
    }
    /*分治法,根据mid是否在最大子数组中讨论。 O(nlogn)*/
    int maxSubArrayHelperFunction(int A[], int left, int right) {
        if(right == left) return A[left];
        int middle = (left+right)/2;
        int leftans = maxSubArrayHelperFunction(A, left, middle);
        int rightans = maxSubArrayHelperFunction(A, middle+1, right);
        int leftmax = A[middle];
        int rightmax = A[middle+1];
        int temp = 0;
        for(int i=middle;i>=left;i--) {
            temp += A[i];
            if(temp > leftmax) leftmax = temp;
        }
        temp = 0;
        for(int i=middle+1;i<=right;i++) {
            temp += A[i];
            if(temp > rightmax) rightmax = temp;
        }
        return max(max(leftans, rightans),leftmax+rightmax);
    } 
};