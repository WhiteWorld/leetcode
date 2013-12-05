class Solution {
public:
    /*l[i]为i位置开始的最长的不重复子串的长度。
    if(s[i]!=s[i+l[i]]) l[i+1]= l[i]-1;
    else l[i+1]=从i+1开始的最长不重复子串
    （计算时利用l[i]的结果从i+l[i]位置开始计算）*/
    int lengthOfLongestSubstring(string s) {
        string str;
        int max=-1;
        for(int i=0;i<s.size();i++)
            if(str.find(s[i]) == string::npos)
                str.push_back(s[i]);
            else
                break;
        max=str.size();
		for(int i=1;(i-1+str.size())<s.size();i++){
            if(s[i-1+str.size()]!=s[i-1]){
                str=str.substr(1);
            }else{
				str.push_back(s[i-1]);
				str=str.substr(1);
                for(int j=i+str.size();j<s.size();j++)
                    if(str.find(s[j])!=string::npos)
                        break;
                    else{
                        str.push_back(s[j]);
					}
                if(str.size()>max)
                    max=str.size();
            }
		}
        return max;
    }


};