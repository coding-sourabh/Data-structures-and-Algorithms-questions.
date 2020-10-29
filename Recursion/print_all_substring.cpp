Given a string str your task is to complete the function spaceString which takes only one argument the string str and  finds all possible strings that can be made by placing spaces (zero or one) in between them. 

For eg .  for the string abc all valid strings will be
                abc
                ab c
                a bc
                a b c

Example 1:

Input:
str = abc
Output: abc$ab c$a bc$a b c$

********************************************************************************************************************************************************************************

void findALLStrings(vector<string>&ans , char *str , int l , int n ,string curString )
{
    if(l == n)
    {
        ans.push_back(curString);
        return;
    }
    
    findALLStrings(ans , str , l+1 , n , curString + " " + str[l] );
    findALLStrings(ans , str , l+1 , n , curString + str[l]);
    
}

vector<string>  spaceString(char str[])
{
    
    int n = strlen(str);
    
    vector<string>ans;
    
    string curString = "";
    curString += str[0];
    
    findALLStrings(ans , str , 1 , n , curString);
    
        reverse(ans.begin() , ans.end());
    return ans;
}
