#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*直接暴力即可。。注意重复值要过滤掉*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {

		vector<vector<int>> ret;
		if(num.size()<3)
			return ret;
		sort(num.begin(),num.end());
		int lasti=num[0]-1;
		for(int i=0;i<num.size()-2;i++){
			if(num[i]==lasti)
				continue;
			int lastj=num[i+1]-1;
			for(int j=i+1;j<num.size()-1;j++){
				if(num[j]==lastj)
					continue;
				int lastk=num[j+1]-1;
				for(int k=j+1;k<num.size();k++){
					if(num[k]==lastk)
						continue;
					if(num[i]+num[j]+num[k]==0){
						vector<int> v;
						v.push_back(num[i]);
						v.push_back(num[j]);
						v.push_back(num[k]);
						ret.push_back(v);
						break;
					}
					lastk=num[k];
						
				}
				lastj=num[j];
			}
			lasti=num[i];
		}
		return ret;
    }
};
int main(){

	Solution solution;
	//string strin;
	//vector<string> str;
	int a;
	vector<int> va;
	while(cin>>a){
		va.push_back(a);
	}
	solution.threeSum(va);
	
	//cout<<str<<endl;
	//solution.prints();
	system("PAUSE");
	return 0;
}