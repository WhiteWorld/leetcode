#include <iostream>
#include <cstring>
using namespace std;
/*两次反转，一次整体反转，一次单词反转
 *注意要求，不要有前置和后置空格，以及单词间空格数为1
 * */
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
			//delete space between words
			in_word=false;
			int start=0,cnt=0;
			for(int i=0;i<s.size();i++){
				if(s[i]!=' '&&in_word==false){
						if(cnt>1)
							s.erase(start,cnt-1);
						in_word=true;
						cnt=0;
						i=start+1;
				}else if(s[i]==' '&&in_word==true){
						in_word=false;
						start=i;
				}
				if(!in_word){
					cnt++;
				}
			}
			if(!in_word){
				s.erase(start,cnt);
			}
			//delete heading and tail zero
			if(s[0]==' ')
					s.erase(0,1);
			if(s[s.size()-1]==' ')
					s.erase(s.size()-1,1);
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
