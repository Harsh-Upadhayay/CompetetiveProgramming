//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

template <class T> class Node {
public:
  T data;
  Node *next = NULL;

  Node(T t) { data = t; }
};

template <class T> class Stack {
private:
  Node<T> *top = NULL;

public:
  void push(T t) {
    Node<T> *node = new Node<T>(t);

    if (top == NULL) {
      top = node;

    } else {
      node->next = top;
      top = node;
    }
  }

  T pop() {
    if (top == NULL) {
      return NULL;
    }

    Node<T> *old_top = top;
    T value = top->data;
    top = top->next;
    delete old_top;
    return value;
  }

  bool is_empty() { return top == NULL; }

  T peek() {
    if (top == NULL) {
      return NULL;
    }

    return top->data;
  }

  void print() {
    Node<T> *node = top;
    while (node != NULL) {
      cout << node->data << " ";
      node = node->next;
    }
    cout << endl;
  }
};

class ItoP {
private:
  Stack<string> stack;
  string str;
  int i;

  bool is_operator(string s) {
    if (s.length() != 1) {
      return false;
    }

    if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' ||
        s[0] == '^') {
      return true;
    }

    return false;
  }

  bool is_bracket(string s) {
    if (s.length() != 1) {
      return false;
    }

    if (s[0] == '(' || s[0] == ')') {
      return true;
    }

    return false;
  }

  int get_precedence(char o) {
    if (o == ')') {
      return 0;
    } else if (o == '+' || o == '-') {
      return 1;

    } else if (o == '*' || o == '/') {
      return 2;

    } else if (o == '^') {
      return 3;
    }

    return -1;
  }

  // is o1 > o2?
  bool is_this_higher_precedence(string o1, string o2) {
    int precedence1 = get_precedence(o1[0]);
    int precedence2 = get_precedence(o2[0]);

    // if (precedence1 == 3 && precedence2 == 3) {
    //   return false;
    // }

    return precedence1 >= precedence2;
  }

  void push(string s) {

    if (is_operator(s)) {
      stack.push(s);

    } else if (is_bracket(s)) {
      if (s == "(") {
        stack.push(s);

      } else {
        string element = stack.pop();
        stack.pop();
        push(element);
      }

    } else {
      if (stack.is_empty() || stack.peek() == "(") {
        stack.push(s);

      } else {
        if (i == str.length() - 1) {
          string oper = stack.pop();
          string prev = stack.pop();
          string element = prev + s + oper;
          push(element);

        } else {
          if (is_this_higher_precedence(stack.peek(), str.substr(i + 1, 1))) {
            string oper = stack.pop();
            string prev = stack.pop();
            string element = prev + s + oper;
            push(element);

          } else {
            stack.push(s);
          }
        }
      }
    }
  }

public:
  string get_postfix(string s) {
    str = s;
    i = 0;

    while (i != s.length()) {

      push(s.substr(i, 1));

      i++;
    }

    return stack.pop();
  }
};
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        ItoP obj;
        
        return obj.get_postfix(s);
        // Your code here
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends