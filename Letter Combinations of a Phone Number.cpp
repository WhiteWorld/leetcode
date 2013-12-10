#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*穷举法。注意数字[7]和数字[9]分别代表4个字符。*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
		int len=digits.length();
		vector<string> ret;
		int t=1;
		for(int i=0;i<len;i++){
			if(digits[i]=='7'||digits[i]=='9')
				t=t*4;
			else
				t=t*3;
		}
		for(int i=0;i<t;i++){
			string str;	
			for(int j=0;j<len;j++){
				int num=digits[j]-'0';//2-9
				int w;
				char ch;
				int p=getPow(j,digits);
				if(num<7){
					w=i%(3*p)/p;//0 1 2
					ch=(num-2)*2+num-2+'a'+w;
				}else if(num==7){
					w=i%(4*p)/p;//0 1 2 3
					ch=(num-2)*2+num-2+'a'+w;
				}else if(num==8){
					w=i%(3*p)/p;
					ch=(num-2)*2+num-1+'a'+w;
				}else if(num==9){
					w=i%(4*p)/p;
					ch=(num-2)*2+num-1+'a'+w;
				}
				str.push_back(ch);
			}
			ret.push_back(str);
		}
        return ret; 
    }
private:
	int getPow(int n,string digits){
		int ret=1;
		for(int i=0;i<n;i++){
			if(digits[i]=='7'||digits[i]=='9')
				ret=ret*4;
			else
				ret=ret*3;
		}
		return ret;
	}
};
int main(){
	Solution solution;
	string strin;
	vector<string> str;
	cin>>strin;
	str=solution.letterCombinations(strin);
	for(int i=0;i<str.size();i++)
		cout<<str[i]<<endl;	
	system("PAUSE");
	return 0;
}