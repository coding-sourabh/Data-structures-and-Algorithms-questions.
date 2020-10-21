Given a string s, recursively remove adjacent duplicate characters from the string s. The output string should not have any adjacent duplicates.
 
Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case contains a string str.

Output:
For each test case, print a new line containing the resulting string.

Example:
Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac

*******************************************************************************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;
#define vi               vector<int>
#define pii              pair<int,int>
#define si               set<int>
#define ff               first
#define ss               second
#define mii              map<int,int>
#define umii             unordered_map<int,int>
#define p_b              push_back
#define pqi               priority_queue<int>
#define loop(i,a,b)      for(int i=a;i<b;i++)
#define int              long long
#define io          	 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define multipletest     int t;cin>>t;while(t--) 
bool isPrime(int n){if(n==1){return false;}if(n==2){return true;}if(n%2==0){return false;}for(int i = 3; i <= sqrt(n); i+=2){if(n % i == 0){return false;}}return true;}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////f//////////////////////////////////////////////////////////////////////////////

void removeDup(stack<char>&st , stack<char> &aux)
{
    
    bool mainCheck = false;
    
    while(!st.empty())
    {
        char ch = st.top();
        st.pop();
        
        bool enter = false;
        
        while(!st.empty() && ch == st.top())
        {
            mainCheck = true;
            enter = true;
            st.pop();
        }
        
        if(!enter)
          aux.push(ch);
    }
    
    if(mainCheck)
        removeDup(aux , st);
    
}

void solve()
{
   string s;
   cin>>s;
   
   stack<char> st , aux;
   
   for(auto x : s)
     st.push(x);
   
   removeDup(st , aux);
   
   string ans = "";
   
   if(st.size() > 0)
   {
       while(!st.empty()) {
       ans += st.top();
       st.pop();
       }
       reverse(ans.begin() , ans.end());
       cout<<ans<<endl;
   }
   else
   {
       while(!aux.empty()){
         ans += aux.top();
         aux.pop();
       }
       
       cout<<ans<<endl;
   }
}

int32_t main()
{
	io
 	multipletest
	solve();
}
