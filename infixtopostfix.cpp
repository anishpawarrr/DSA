#include <bits/stdc++.h>
using namespace std;

template <class T>

class Stack
{
public:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *top = new Node;

    Stack()
    {
        top = NULL;
    }
    void push(T p)
    {
        Node *temp = new Node;
        temp->data = p;
        temp->next = top;
        top = temp;
    }
    T pop()
    {
        T temp = top->data;
        if (top != NULL)
        {
            top = top->next;
        }
        return temp;
    }
    void display()
    {
        Node *temp = new Node;
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool isempty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    T getop()
    {
        return top->data;
    }
};

int decide(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isoperator(char c)
{
    if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string convert(string s)
{
    string answer = "";
    Stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (!isoperator(s[i]) && s[i] != '(' && s[i] != ')')
        {
            answer.push_back(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (st.getop() != '(')
            {
                answer.push_back(st.getop());
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.isempty() && decide(s[i]) <= decide(st.getop()))
            {
                answer.push_back(st.getop());
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.isempty())
    {
        answer.push_back(st.getop());
        st.pop();
    }
    cout << answer << endl;
    return answer;
}

int main()
{
    string s = "(a+b)*(c-d)";
    convert(s);
    return 0;
}
