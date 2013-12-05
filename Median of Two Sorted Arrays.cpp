class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        vector<int> C;
        //if(sizeof(A)==0||sizeof(B)==0)
        // 题目假定A B 都是升序的
        for(int ia=0,ib=0;ia<m||ib<n;){
            if(ia>=m){
                C.push_back(B[ib]);
                ib++;
                continue;
            }
            if(ib>=n){
                C.push_back(A[ia]);
                ia++;
                continue;
            }
            if(A[ia]<B[ib]){
                C.push_back(A[ia]);
                ia++;
            }else if(A[ia]>=B[ib]){
                C.push_back(B[ib]);
                ib++;
            }
        }
        if(C.size()%2)
            return C[C.size()/2];
        else
            return (C[C.size()/2]+C[C.size()/2-1])/2.0;
        
    }
};