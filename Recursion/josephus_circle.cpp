
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.â€‹
The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.

Example 1:

Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so 
skipping 1 person i.e 1st person 2nd 
person will be killed. Thus the safe 
position is 3.

*****************************************************************************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;

int position(vector<int>a , int n , int k , int startPos)
{
    if(a.size() == 1)                 
      return a[0];
                                            
    int skip = (startPos + k) % n;          
    
    a.erase(a.begin() + skip);
    
    return position(a , a.size() , k , skip % a.size());
}

int josephus(int n, int k)
{
    vector<int> a(n);
    
    for(int i=0 ; i < n; i++)
    {
        a[i] = i;
    }
    
    return position(a , n , k-1 , 0) + 1;
}

int main()
{
   int n , k ; 
   cin>>n>>k;
   
   cout<<josephus(n , k)<<endl;
   
   return 0;
}
