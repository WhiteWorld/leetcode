class Solution {
public:
    /*在Subset 的基础上，遇到相同的元素，加入到相同元素最多的那些上面。*/
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        std::sort(S.begin(), S.end());
        vector<vector<int> > result;
        if(S.size()==0)
            return result;
        vector<int> v;
        result.push_back(v);
        v.push_back(S[0]);
        result.push_back(v);
        int num=1;//代表有多少个连续S[i-1]
        for(int i=1;i<S.size();i++){
            int old_size = result.size();
            for(int j=0;j<old_size;j++){
                vector<int> v = result[j];
                if(S[i]==S[i-1]){
                    if(v.size()>=num && v[v.size()-num] == S[i]){
                        v.push_back(S[i]);
                        result.push_back(v);
                    }
                }else{
                    v.push_back(S[i]);
                    result.push_back(v);
                }
            }
           if(S[i]==S[i-1])
                num++;
            else
                num=1;
        }
        return result;
    }
};