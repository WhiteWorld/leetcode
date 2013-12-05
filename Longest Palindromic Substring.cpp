#include <iostream>
#include <string>
using namespace std;


class Solution {
public:

	string longestPalindrome(string s) {
		
		/*dp O(n^2)，The Key Is dp[i][j] :between i and j(include i,j) ,if has a Palindrome*/
		bool dp[1001][1001];
		int len=0;
		len=s.size();
		if(len==0)
			return s;
		for(int i=0;i<len;i++)
			dp[i][i]=1;
		for(int i=1;i<len;i++)
			dp[i][i-1]=1;
		int start,stop;
		start=1;
		stop=0;
		for(int m=0;m<len;m++){//m: interval of i and j
			for(int i=0;i<len-m;i++){
				int j=i+m;
				if((i==j)||(s[i]==s[j]&&dp[i+1][j-1]==1)){
					dp[i][j]=1;
					if(stop-start<m){
						start=i;
						stop=j;
					}
				}else{
					dp[i][j]=0;
				}
			}
		}
		return s.substr(start,stop-start+1);
	}
		
	string longestPalindrome2(string s){
		/*暴力算法，O(n^3),超时*/
		int l[1001];
		int max=-1;
		int result;
		for(int i=0;i<s.size();i++){
			l[i]=1;
			for(int j=s.size();j>i;j--){
				if(isPalindrome(s,i,j)){
					l[i]=j-i+1;
					break;
				}             
			}
			if(l[i]>max){
				max=l[i];
				result=i;
			}
			
		}
		return s.substr(result,max);
	}
	bool isPalindrome(string s,int begin,int end){//make sure begin < end
		while(begin<end){
			if(s[begin]!=s[end])
				return false;
			begin++;
			end--;
		}
		return true;
	}
};
int main(){

	Solution solution;
	string str;
	while(cin>>str){
		cout<<solution.longestPalindrome(str)<<endl;	
	}
	system("PAUSE");
	return 0;
}