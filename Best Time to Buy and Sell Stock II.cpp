class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1)
            return 0;
        int profit=0;
        int min = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[i-1]){
                profit += (prices[i-1]-min);
                min = prices[i];
            }else{
                if(i == prices.size()-1)
                    profit += (prices[i]-min);
            }
            
        }

        return profit;
    }
};