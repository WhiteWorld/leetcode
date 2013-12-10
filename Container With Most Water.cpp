/*从首尾向中间逼近，最终的结果一定包含最优解。
证明方法：反证法。如果从首尾逼近的过程中没有包含最优解，，，，最终推出矛盾。*/
class Solution {
public:
    int maxArea(vector<int> &height){
       int len = height.size(), low = 0, high = len -1 ;  
       int maxArea = 0;  
       while (low < high) {  
         maxArea = max(maxArea, (high - low) * min(height[low], height[high]));  
         if (height[low] < height[high]) {  
           low++;  
         } else {  
           high--;  
         }  
       }  
       return maxArea;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
    int min(int a,int b){
        return a>b?b:a;
    }
};