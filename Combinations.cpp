class Solution {
public:
/*直观的递归解*/
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if(k == 1){
            for(int i=1;i<=n;i++){
                vector<int> v;
                v.push_back(i);
                result.push_back(v);
            }
            return result;
        }
        if(n == k){
            vector<int> v;
            for(int i=1;i<=n;i++)
                v.push_back(i);
            result.push_back(v);
            return result;
        }
        result = combine(n-1, k-1);
        for(int i=0;i<result.size();i++)
            result[i].push_back(n);
        vector<vector<int> > vt = combine(n-1, k);
        result.insert(result.begin(), vt.begin(), vt.end());
        return result;
    }
};