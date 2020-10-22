Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "snakesandladder",
dict = ["snake", "snakes", "and", "sand", "ladder"].

A solution is ["snakes and ladder",
           "snake sand ladder"].

Input:
The first line contains an integer T, denoting the number of test cases.
Every test case has 3 lines.
The first line contains an integer N, number of words in the dictionary.
The second line contains N strings denoting the words of the dictionary.
The third line contains a string s.

Output:
For each test case, print all possible strings in one line. Each string is enclosed in (). See Example.
If no string possible print "Empty" (without quotes).

Note: Make sure the strings are sorted in your result.

Exapmle:
Input:
1
5
lr m lrm hcdar wk
hcdarlrm

Output:
(hcdar lr m)(hcdar lrm)

********************************************************************************************************************************************************************************

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

void find(vector<string> &ans , string str , set<string> dict , string cur="")
{
    if(str.size() == 0)
     {
         ans.push_back(cur);
         return;
     }
    
    for(int i=0 ; i < str.size() ; i++)
    {
        string sub = str.substr(0 , i+1);
        
        if(dict.count(sub) == 1)
            find(ans , str.substr(i+1) , dict , cur + sub + " ");
    }
    
}

void solve()
{
    int n;
    cin>>n;
    
    set<string> dict;
    
    for(int i=0 ; i < n ;i++)
     {
         string s;
         cin>>s;
         dict.insert(s);
     }
    
    string str;
    cin>>str;
    
    vector<string>ans;
    
    find(ans , str , dict );
    
    for(auto x : ans)
    {
        cout<<"(";
        for(int i=0 ; i < x.size()-1 ; i++)
        {
            cout<<x[i];
        }
        cout<<")";
    }
    
    cout<<endl;
}

int32_t main()
{
	io
 	multipletest
	solve();
}
