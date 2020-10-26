Given an integer n. Print first n elements of Recaman’s sequence.
It is basically a function with domain and co-domain as natural numbers and 0. It is recursively defined as below:
Specifically, let a(n) denote the (n+1)-th term. (0 being already there).
The rule says:

a(0) = 0
a(n) = a(n-1) - n if a(n-1) - n > 0 and not used previously
       a(n-1) + n otherwise.

ex : 0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 11, 22, 10, 23, 9, 24, 8, 25, 43, 62, 42, 63, 41, 18 ........

*************************************************************************************************************************************************************************************
class Solution{
public:
    
    void helper(vector<int> &ans , int n)
    {
        if(n == 0)
        {
            ans.push_back(0);
            return;
        }
        
        helper(ans , n-1);
        
        if(ans[ans.size()-1] - n > 0 && find(ans.begin() , ans.end() , ans[ans.size()-1] - n) == ans.end())
           ans.push_back(ans[ans.size()-1] - n);
        else
           ans.push_back(ans[ans.size()-1] + n);
        
    }

    vector<int> recamanSequence(int n){
        
        vector<int> ans;
        
        helper(ans , n);
        
        return ans;
    }
};
