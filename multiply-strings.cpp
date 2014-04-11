/**/
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> result(len1+len2+1);
        for(int i=len2-1;i>=0;i--){
            int start=len2-1-i;
            for(int j=len1-1;j>=0;j--){
                result[start]+=(num2[i]-'0')*(num1[j]-'0');
                start++;
            }
        }
        for(int i=0;i<len1+len2+1;i++)
            if(result[i]>9){
                result[i+1]+=result[i]/10;
                result[i]=result[i]%10;
            }
        int len = len1+len2;
        while(result[len]==0&&len>0){
            len--;
        }
        string ans;
        int j=0;
        for(int i=len;i>=0;i--)
            ans.push_back(result[i]+'0');
        return ans;
    }
};