#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*先排序，然后比较第一个和最后一个的最长公共前缀，即为结果。输入为空，输出也为空。*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret;
        if(strs.size()==0)
            return ret;
		sort(strs.begin(),strs.end());
        int i=0;
        for(i=0;i<strs[0].size()&&i<strs[strs.size()-1].size();i++){
            if(strs[0][i]!=strs[strs.size()-1][i])
                break;
        }
        return strs[0].substr(0,i);
    }
};
int main(){

	Solution solution;
	string strin;
	vector<string> str;
	while((cin>>strin)){
		str.push_back(strin);
	}
	cout<<solution.longestCommonPrefix(str)<<endl;
	
	//cout<<str<<endl;
	//solution.prints();
	system("PAUSE");
	return 0;
}