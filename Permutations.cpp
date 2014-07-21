/*assume the numbers are set, without duplicates*/
/*递归解*/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        return permute_helper(num, num.size());
    }
    vector<vector<int> > permute_helper(vector<int> &num, int n){
        vector<vector<int> > result;
        if(n==0)
            return result;
        if(n==1){
            vector<int> t;
            t.push_back(num[0]);
            result.push_back(t);
            return result;
        }
        vector<vector<int> > pre_result = permute_helper(num, n-1);
        std::vector<int>::iterator it;
        for(int i=0;i<pre_result.size();i++){
            for(int j=0;j<=pre_result[i].size();j++){
                vector<int> t;
                t = pre_result[i];
                it = t.begin();
                t.insert(it+j, num[n-1]);
                result.push_back(t);
            }
        }
    }
};