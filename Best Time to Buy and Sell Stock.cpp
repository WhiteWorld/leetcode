/*从前往后扫描，维护一个最小值和最大利润，如果大于最小值则比较是否超过最大利润*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0)
            return 0;
        int min=prices[0];
        int result=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min)
                min=prices[i];
            else{
                if(prices[i]-min>result)
                    result = prices[i]-min;
            }
        }
        return result;
    }
};