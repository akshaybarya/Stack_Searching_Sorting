#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int RainWater(vector<int> &a, int n)
{
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            int curr = st.top();
            st.pop();

            if (st.empty())
            {
                break;
            }

            int diff = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[curr]) * diff;
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }

    cout << RainWater(a, n) << endl;

    return 0;
}
