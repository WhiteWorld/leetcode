class Solution {
public:
    /*两种情况 全为9和非全为9*/
    vector<int> plusOne(vector<int> &digits) {
        bool flag=true;//true is all nine
        vector<int> result = digits;
        for(int i=0;i<result.size();i++)
            if(result[i]!=9){
                flag=false;
                break;
            }
        if(!flag){
            result[result.size()-1]++;
            for(int i=result.size()-1;i>0;i--)
                if(result[i]>9){
                    result[i-1]+=result[i]/10;
                    result[i]=result[i]%10;
                }
        }else{
            result[0]=1;
            for(int i=1;i<result.size();i++)
                result[i]=0;
            result.push_back(0);
        }
        
        return result;
        
    }
};