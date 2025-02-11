// C++
class Solution
{
public:
    bool check(stack<char> &st, string part)
    {
        stack<char> tempSt = st;
        for (int i = part.size() - 1; i >= 0; i--)
        {
            if (tempSt.top() != part[i])
            {
                return false;
            }
            tempSt.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part)
    {
        stack<char> st;
        int i = 0;
        while (i < s.size())
        {
            st.push(s[i]);
            if (st.size() >= part.size() && check(st, part) == true)
            {
                for (int j = 0; j < part.size(); j++)
                {
                    st.pop();
                }
            }
            i++;
        }
        string res = "";
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// JAVA
class Solution
{
public
    boolean check(Stack<Character> st, String part)
    {
        Stack<Character> tempSt = new Stack<Character>();
        tempSt.addAll(st);

        for (int i = part.length() - 1; i >= 0; i--)
        {
            if (tempSt.isEmpty() || tempSt.peek() != part.charAt(i))
            {
                return false;
            }
            tempSt.pop();
        }
        return true;
    }
public
    String removeOccurrences(String s, String part)
    {
        Stack<Character> st = new Stack<>();
        int i = 0;
        while (i < s.length())
        {
            st.push(s.charAt(i));
            if (st.size() >= part.length() && check(st, part))
            {
                for (int j = 0; j < part.length(); j++)
                {
                    if (!st.isEmpty())
                    {
                        st.pop();
                    }
                }
            }
            i++;
        }
        StringBuilder res = new StringBuilder();
        while (!st.isEmpty())
        {
            res.append(st.pop());
        }
        return res.reverse().toString();
    }
}
