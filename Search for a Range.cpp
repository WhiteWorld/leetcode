class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        if (n==0){
            result.push_back(-1);
            result.push_back(-1);
        }else if(n==1){
            if(A[0]==target){
                result.push_back(0);
                result.push_back(0);
            }else{
                result.push_back(-1);
                result.push_back(-1);
            }
        }else{
            if(A[0]>target || A[n-1]<target){
                result.push_back(-1);
                result.push_back(-1);        
            }else{
                int pos = searchHelper1(A, 0, n-1, target);
                if(pos == -1){
                    result.push_back(-1);
                    result.push_back(-1);                
                }else{
                    result.push_back(pos);
                    pos = searchHelper2(A, pos, n-1, target, n);
                    result.push_back(pos);
                }
            }
        }
        return result;
        
    }
    /*根据起始位置，找结尾位置*/
    int searchHelper2(int A[], int s, int e, int target, int n){
        while(s<=e){
            int mid = (s+e)/2;
            if(A[mid]==target){
                if(mid == n-1)
                    return n-1;
                else if(A[mid+1]!=target)
                    return mid;
                else
                    s = mid + 1;
            }else{//A[mid]>target
                e = mid - 1;
            }
        }
    }
    
    /*get first target or not*/
    int searchHelper1(int A[], int s, int e, int target){
        while(s<=e){
            int mid = (s+e)/2;
            if(A[mid]==target){
                if(mid==0)
                    return 0;
                else if(A[mid-1]!=target)
                    return mid;
                else
                    e = mid - 1;
                    
            }else if(A[mid]< target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return -1;
    }
};