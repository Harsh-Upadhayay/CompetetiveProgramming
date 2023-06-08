//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string expression) {
  std::stack<char> stk;

  for (char c : expression) {
    if (c == '(' || c == '[' || c == '{') {
      stk.push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      if (stk.empty()) {
        return false;
      }
      char top = stk.top();
      stk.pop();
      if ((c == ')' && top != '(') || (c == ']' && top != '[') ||
          (c == '}' && top != '{')) {
        return false;
      }
    }
  }

  return stk.empty();
}
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends