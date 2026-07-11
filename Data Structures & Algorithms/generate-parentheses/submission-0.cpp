class Solution {
public:
    void helper(int n, int open, int close, vector<string>& ans,string& str){
        if(str.size() == 2 * n){
            ans.push_back(str);
            return;
        }
        if(open < n){
            str+='(';
            helper(n,open+1,close,ans,str);
            str.pop_back();

        }
        if(close < open){
            str+=')';
            helper(n,open,close+1,ans,str);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0 ; 
        int close = 0 ; 
        string str = "";
        vector<string> ans;
        helper(n,open,close,ans, str);
        return ans;
    }
};
