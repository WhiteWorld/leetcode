class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        int len = lena>lenb?lena:lenb;
        string result(len+1, '0');
        lena--;
        lenb--;
        while(lena>=0||lenb>=0){
            char cha,chb;
            if(lena<0){
                cha='0';
                chb=b[lenb];
            }else if(lenb<0){
                cha=a[lena];
                chb='0';
            }else {
                cha = a[lena];
                chb = b[lenb];
            }
            result[len]+=(cha-'0'+chb-'0');
            if(result[len]>'1'){
                result[len]-=2;
                result[len-1]+=1;
            }
            lena--;
            lenb--;
            len--;
        }
        if(result[0]=='1')
            return result;
        else
            return result.substr(1,result.length()-1);
        
    }
};