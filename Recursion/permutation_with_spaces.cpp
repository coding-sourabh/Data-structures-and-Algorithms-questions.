Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. 
Output should be printed in sorted increasing order of strings.

Input:  str[] = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Input:
First line contains the test cases T.  1<=T<=10
Each test case have one line string S of characters of length  N.  1<=N<=10

Output:
One line per test case, every string enclosed in ().(See example). Output should be printed in sorted order.

Example:
Input:
2
AB
ABC

Output:
(A B)(AB)
(A B C)(A BC)(AB C)(ABC)

******************************************************************************************************************************************************************************

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

void printAll(string s , int curInd , int n , string curStr)
{
    if(curInd == n)
    {
        cout<<"("<<curStr<<")";
        return;
    }
    
    printAll(s , curInd + 1 , n , curStr + " " + s[curInd]);
    printAll(s , curInd + 1 , n , curStr + s[curInd]);
    
}

void solve()
{
    string s;
    cin>>s;
    
    string curStr = "";
    curStr += s[0];
    
    printAll(s , 1 , s.size() , curStr);
    cout<<endl;
}

int32_t main()
{
	io
 	multipletest
	solve();
}
