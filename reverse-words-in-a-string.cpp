#include <iostream>
#include <cstring>
using namespace std;
class Solution {
	public:
		void reverseString(string &s){
			int left=0;
			int right=s.size()-1;
			while(left<right){
				char tmp=s[left];
				s[left]=s[right];
				s[right]=tmp;
				left++;
				right--;
			}
		}
		void reverseWord(string &s, int l,int r){
			while(l<r){
				char tmp=s[l];
				s[l]=s[r];
				s[r]=tmp;
				l++;
				r--;
			}
		}

		void reverseWords(string &s) {
			if(s.size()==0)
				return ;
			reverseString(s);
			int l,r;
			l=0;
			bool in_word=false;
			for(int i=0;i<s.size();i++){
				if(s[i]!=' '&&in_word==false){
					l=i;
					in_word=true;
				}else if(s[i]==' '&&in_word==true){
					r=i-1;
					reverseWord(s,l,r);
					in_word=false;					
				}
			}
			if(in_word){
				reverseWord(s,l,s.size()-1);
			}
		}
		
};
int main(){
	Solution s;
	string str;
	getline(cin,str);
	s.reverseWords(str);
	cout<<str<<endl;
	return 0;
}
