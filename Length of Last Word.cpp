class Solution {
public:
    /*网上：简单*/
    int lengthOfLastWord(const char *s) {
        int length = strlen(s);
        for (length--; length >= 0 && s[length] == ' '; length--) ;
        int res = 0;
        for (int i = length; i >= 0 && s[i] != ' '; i--, res++) ;
        return res;
    }
    /*我：太复杂了*/
    int lengthOfLastWord1(const char *s) {
        if(*s=='\0')
            return 0;
        int pos=-1;
        int last_space=-1;
        int last_a = -1;
        int index=0;
        while(*s!='\0'){
            if(*s == ' '){
                if(*(s+1)!='\0'&&*(s+1)!=' ')
                    pos=index;
                last_space = index;
            }else{
                last_a = index;
            }
            index++;
            s++;
        }
        if(last_space == -1)
            return index;
        if(last_a == -1)
            return 0;
        return last_a - pos;
    }
};