#include <iostream>
#include <string>
using namespace std;

/*字符串输入输出，找规律即可*/
class Solution {
public:
    string convert(string s, int nRows) {
		if(nRows==1)
			return s;
		
		// assume nRows>=2
		int n=s.size();
		string ret;
		//get fisrt row
		int t=2*(nRows-1);
		int cur=0;
		while(cur<n){
			ret+=s[cur];
			cur+=t;
		}
		//get second row to nRows-1 row
		for(int row=2;row<=nRows-1;row++){
			bool flag=true;
			int cur=row-1;
			int t1=2*(nRows-row);
			int t2=2*(row-1);
			while(cur<n){
				if(flag){
					ret+=s[cur];
					cur+=t1;
				}else{
					ret+=s[cur];
					cur+=t2;
				}
				flag=!flag;
			}
		}
		//get last row
		t=2*(nRows-1);
		cur=nRows-1;
		while(cur<n){
			ret+=s[cur];
			cur+=t;
		}

		return ret;

    }
};
int main(){

	Solution solution;
	string str;
	int row;
	while(cin>>str>>row){
		cout<<solution.convert(str,row)<<endl;	
	}
	//cout<<str<<endl;
	//solution.prints();
	system("PAUSE");
	return 0;
}