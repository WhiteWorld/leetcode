class Solution {
public:
    /*not care if reverse of x is overflow*/
    int reverse(int x) {
        char str[30];
        int sign;
        if(x<0)
            sign=-1;
        else
            sign=1;
        x*=sign;//let x > 0
        //change x to char[]
        
        if(x==0)
            return x;
        //assume x!=0
        int len=0;
        while(x!=0){
            str[len++]=x%10;
            x/=10;
        }
        //find first bit which is not *zero*
        int i;
        for(i=0;i<len;i++){
            if(str[i]!=0)
                break;
        }
        int ret=0;
        int t=1;
        for(int j=len-1;j>=i;j--){
            ret+=str[j]*t;
            t*=10;
        }
        return ret*sign;
        
    }
};