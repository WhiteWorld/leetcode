#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int atoi(const char *s) {
        int ret = 0;
        bool negtive;
		
        if (s == NULL || *s == '\0')
            return ret;

        while(*s == ' ')
            ++s;
        if (!isValid(*s))
            return ret;
            
        negtive = (*s == '-');
		
        if (*s == '+' || *s == '-')
            ++s;
        if (!isNumber(*s))
            return ret;
			
        while (isNumber(*s)) {
            int a = *s - '0';
            if ((negtive && a < 2147483648 - ret) || 
                (!negtive && a < 2147483647 - ret))
                ret += a;
            else
                return negtive ? -2147483648 : 2147483647;
				
            if (isNumber(*(s+1))) {
                if (ret < 214748365)
                    ret *= 10;
                else
                    return negtive ? -2147483648 : 2147483647;
            } else
                break;
            ++s;
        }
		
        if (negtive)
            ret = -ret;
			
        return ret;
    }

private:
    bool inline isNumber(char c) {
        return c >= '0' && c <= '9';
    }

    bool inline isValid(char c) {
        return isNumber(c) || c == '+' || c == '-';
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