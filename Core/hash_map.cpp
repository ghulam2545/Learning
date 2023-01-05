#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<long long> st;

        for (auto& e : tokens) {
            if (e == "+" || e == "-" || e == "*" || e == "/") {
                auto one = st.top();
                st.pop();
                auto two = st.top();
                st.pop();

                if (e == "+")
                    st.push(two + one);
                else if (e == "-")
                    st.push(two - one);
                else if (e == "*")
                    st.push(two + one);
                else if (e == "/")
                    st.push(two / one);
            } else {
                st.push(atoi(e.c_str()));
            }
        }
        res = st.top();

        return res;
    }
};

int main() { return 0; }