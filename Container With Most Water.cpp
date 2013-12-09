class Solution {
public:
// 	typedef struct {
// 		int h,w;
// 	}Square;
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
// 	int maxArea(vector<int> &height){
// 		int len=height.size();
// 		int max=-1;
// 		int d;
// 		for(int m=0;m<len;m++){
// 			for(int i=0;i<len-m;i++){
// 				int j=i+m;
// 				d=(height[i]>height[j]?height[j]:height[i]);
// 				if(d*(j-i)>max)
// 					max=d*(j-i);
// 			}
// 		}
// 		return max;
// 	}
};