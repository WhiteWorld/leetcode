#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int atoi(const char *str) {
        /*
		==========AC前============
		char in  string ?
         [0-9 . + -]
		 whitespace
         Is it a valid *int* num?
         compare with INT_MAX  and INT_MIN
         
         默认只能是10进制

		=============AC后================
		 1.str中可能有空格，空格在最前面，过滤掉空格再计算
		 2.我考虑了小数点，测试案例中没有小数点的情况
		 3.+ - 的情况
		 3.从前往后出现的第一个连续数字串，组成的整数，放到long long 中，与INT_MAX INT_MIN比较
		 4.异常情况一律返回0
         */
         long long ret=0;
         bool sign;// positive or nagetive
         int plus_pos=-1,min_pos=-1,point_pos=-1;
         int plus_num=0,min_num=0,point_num=0;
         int invalid_num=0;
         int start,stop;
         int lenstr=strlen(str);
		 int pre=0;
		 int last=lenstr-1;
		 for(int i=0;i<lenstr;i++)
			 if(str[i]!=' '){
				pre=i;
				break;
			 }
         for(int i=pre;i<lenstr;i++){
             if(str[i]=='.'){
                 point_pos=i;
                 point_num++;
             }else if(str[i]=='+'){
                 plus_pos=i;
                 plus_num++;
             }else if(str[i]=='-'){
                 min_pos=i;
                 min_num++;
			 }else if(str[i]<'0'||str[i]>'9'){
			     last=i-1;
			     break;
                 invalid_num++;
             }
         }
         if(last<pre)
            return 0;
         if(point_num>1||plus_num>1||min_num>1||invalid_num>0)
            return 0;
         if(plus_num==1&&min_num==1)
            return 0;

        if(min_num==1&&min_pos!=pre)
            return 0;
        if(plus_num==1&&plus_pos!=pre)
            return 0;
        
        //get sign and start(with zero)
        if(min_num==1){
            sign=false;
            start=pre+1;
        }else{
            sign=true;
            if(plus_num==1)
                start=pre+1;
            else
                start=pre;
        }
        //get stop
        if(point_num==1){
            if(point_pos>pre)
                stop=point_pos-1;
            else
                return 0;
		}else{
			stop=last;
		}
        
        //clear zero in front
        for(int i=start;i<=stop;i++){
            if(str[i]!='0'&&str[i]!=' '){
                start=i;
                break;
            }
        }
        //get start--stop num
        long long base=1;
        for(int i=stop;i>=start;i--){
            ret+=(str[i]-'0')*base;
            base*=10;
            if(sign&&ret>INT_MAX)
                return INT_MAX;
            if(!sign&&(-ret)<INT_MIN)
                return INT_MIN;
        }
        int iret;
        if(sign)
             iret=ret;
        else
            iret=-ret;
        return iret;
        
         
         
    }
};
int main(){

	Solution solution;
	string str;
	while(cin>>str){
		cout<<solution.atoi("     +004500")<<endl;	
	}
	//cout<<str<<endl;
	//solution.prints();
	system("PAUSE");
	return 0;
}