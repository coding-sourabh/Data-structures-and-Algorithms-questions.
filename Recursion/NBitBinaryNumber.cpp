Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

Example 1:

Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than 
or equal 1's than 0's
Example 2:

Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more 
than or equal 1's than 0's
User Task:
Your task is to complete the function NBitBinary() which takes a single number as input and returns the list of strings in decreasing order. 
You need not take any input or print anything.

********************************************************************************************************************************************************************************

void findAll(vector<string> &ans , int N , string cur , int oneCount , int req)
    {
        if(N == 0)
        {
            if(req <= 0)
            ans.push_back(cur);
            return;
        }
        
        
        findAll(ans , N-1 ,  cur + '1' , oneCount + 1 , req - 1);
        
        if(oneCount >= 1)
          findAll(ans , N-1 ,  cur + '0' , oneCount - 1 , req);
        
    }
    
	vector<string> NBitBinary(int N)
	{
	    string s = "1";
	    vector<string>ans;
	    
	    int req = (N+1)/2;
	    
	    findAll(ans , N-1 , s , 1 , req - 1);
	    
	    return ans;
	}
	
};
