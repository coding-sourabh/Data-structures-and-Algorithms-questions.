Author : sourabh kumar
Date Created : 22 / 10 / 20

Given a string S. The task is to print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA

******************************************************************************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;

set<string>st;

void allpermute(string s , int curDes = 0)
{
   if(curDes == s.size()-1)
   	  {
   	     st.insert(s);
   	  	 return;
   	  }

   	for(int i=curDes ; i < s.size() ; i++)
   	{
   		swap(s[curDes] , s[i]);

        allpermute(s , curDes+1);

   		swap(s[curDes] , s[i]);
   	}

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        st.clear();
        
        string s;
        cin>>s;
        
        allpermute(s , 0);
        
        for(auto it : st)
          cout<<it<<" ";
        
        cout<<endl;
    }
	return 0;
}
