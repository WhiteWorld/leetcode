/*左括号直接进栈，右括号直接与栈顶元素比较。*/
class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty())
                    return false;
                else if(st.top()=='('){
                    st.pop();
                }else{
                    return false;
                }
            }else if(s[i]=='}'){
                if(st.empty())
                    return false;
                else if(st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }else if(s[i]==']'){
                if(st.empty())
                    return false;
                else if(st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }            
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};