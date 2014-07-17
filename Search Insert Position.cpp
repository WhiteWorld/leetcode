class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return searchInsert2(A, n, target);
    }
    /*O(n)搜索*/
    int searchInsert1(int A[], int n, int target){
        for(int i=0;i<n;i++)
            if(A[i]>=target)
                return i;
        return n;
    }
    /*二分搜索，O(logn)*/
    int searchInsert2(int A[], int n, int target){
        int start = 0;
        int end = n;
        int mid=(start + end)/2;
        while(start < end){
            if(A[mid]==target){
                return mid;
            }else if(A[mid]<target){
                start = mid + 1;
            }else{
                end = mid;
            }
            mid = (start + end)/2;
        }
        if(start == n)
            return n;
        if(A[start] < target)
            return start+1;
        else 
            return start;
    }
    
};