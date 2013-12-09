#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 罗马计数法的特征如下：

数位没有意义，只表示数字本身
没有0
使用I(1)、V(5)、X(10)、L(50)、C(100)、D(500)、M(1000)来记数
将并排的数字加起来，就是所表示的数。

有几条须注意掌握：
基本数字Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
不能把基本数字V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
V 和X 左边的小数字只能用Ⅰ。
L 和C 左边的小数字只能用X。
D 和M 左边的小数字只能用C。
 */
class Solution {
public:
    string intToRoman(int num) {
        int bit[4];
        bit[0]=num/1000;
        bit[1]=num%1000/100;
        bit[2]=num%100/10;
        bit[3]=num%10;
        string ret;
        //string st;
        while(bit[0]>0){
            bit[0]--;
			ret+='M';
        }
        if(bit[1]==9)
			ret+="CM";
        else if (bit[1]==8)
            ret+="DCCC";
        else if(bit[1]==7)
            ret+="DCC";
        else if(bit[1]==6)
            ret+="DC";
        else if (bit[1]==5)
            ret+='D';
        else if(bit[1]==4)
            ret+="CD";
        else if(bit[1]==3)
            ret+="CCC";
        else if (bit[1]==2)
            ret+="CC";
        else if(bit[1]==1)
            ret+='C';
            
        if(bit[2]==9)
            ret+="XC";
        else if (bit[2]==8)
            ret+="LXXX";
        else if(bit[2]==7)
            ret+="LXX";
        else if(bit[2]==6)
            ret+="LX";
        else if (bit[2]==5)
            ret+='L';
        else if(bit[2]==4)
            ret+="XL";
        else if(bit[2]==3)
            ret+="XXX";
        else if (bit[2]==2)
            ret+="XX";
        else if(bit[2]==1)
            ret+='X';   
            
        if(bit[3]==9)
            ret+="IX";
        else if (bit[3]==8)
            ret+="VIII";
        else if(bit[3]==7)
            ret+="VII";
        else if(bit[3]==6)
            ret+="VI";
        else if (bit[3]==5)
            ret+='V';
        else if(bit[3]==4)
            ret+="IV";
        else if(bit[3]==3)
            ret+="III";
        else if (bit[3]==2)
            ret+="II";
        else if(bit[3]==1)
            ret+='I'; 
        return ret;
    }
};
int main(){

	Solution solution;

	cout<<solution.intToRoman(1998)<<endl;	
	//cout<<str<<endl;
	//solution.prints();
	system("PAUSE");
	return 0;
}