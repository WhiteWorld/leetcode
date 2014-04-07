#include <iostream>
#include <cstring>

using namespace std;
/*
 * 使用一个长度为128的数组记录字符是否出现过
从左向右扫描，直到出现重复的，找出重复字符上一个出现的位置的下一位，作为新的位置
*/
class Solution {
		public:
				int lengthOfLongestSubstring(string s) {
						int tab[128];
						memset(tab,0,sizeof(tab));
						int max=0;
						int cnt=0;
						for(int i=0;i!=s.size();i++){
								if(tab[s[i]]==0){
										tab[s[i]]=i+1;
										cnt++;
								}else{
										//cout<<"i:"<<i<<endl;
										//cout<<"cnt:"<<cnt<<endl;
										if(cnt>max)
												max=cnt;
										for(int j=tab[s[i]]-2;j>=i-cnt;j--)
												tab[s[j]]=0;
										cnt = i-tab[s[i]]+1;
										tab[s[i]]=i+1;
								}
						}
						if(cnt>max)
							max=cnt;
						return max;
				}
};


int main(){
	Solution s;
	string str="qopubjguxhxdipfzwswybgfylqvjzhar";
	cout<<s.lengthOfLongestSubstring(str)<<endl;

	return 0;

}
