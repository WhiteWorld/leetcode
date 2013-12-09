class Solution {
public:
    /*
    判断反转后的数与当前数是否相同，相同则为回文数。
    注意：
    1.负数不是回文数
    2.反转后整数可能会溢出，正整数溢出后为负数。
    如果正整数反转后为负数，则肯定不是回文数。

    */
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int bitsNum=getBitsNumber(x);
        int reverse=getReverseNumber(x,bitsNum);
        if(reverse<0)//溢出了，说明不是回文数
            return false;
        if(reverse==x){
            return true;
        }else
            return false;
        
    }
    
    //assume x >= 0
    int getBitsNumber(int x){
        int num=0;
        while(x!=0){
            x=x/10;
            num++;
        }
        return num;
    }
    //assume x>=0
    int getReverseNumber(int x,int num){
        
        int ret=0;
        while(x!=0){
            int t;
            t=x%10;
            ret+=t*int(pow(10,num-1));
            x=x/10;
            num--;
        }
        return ret;
    }
};