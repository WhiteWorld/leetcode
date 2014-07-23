class Solution {
public:
    /**copy from discuss. 思路：把所有的方格减去实心的方格就是空心可以放水的*/
    int trap(int A[], int n) {
        if(n==0) return 0;
        int l = 0, r = n-1,block = 0,all = 0,curlevel = 0;
        while(l<=r)
        {
            if(min(A[l],A[r])>curlevel) 
            {
                all += (min(A[l],A[r])-curlevel)*(r-l+1);
                curlevel = min(A[l],A[r]);
            }
            if(A[l]<A[r]) 
                block += A[l++];
            else 
                block += A[r--];
        }
        return all-block;
    }
};