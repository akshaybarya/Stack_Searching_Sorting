#include <bits/stdc++.h>
using namespace std;

int LargestRectangle(vector<int> &a, int n)
{
    a.push_back(0);
    int i = 0;
    int ans = -1;
    stack<int> st;
    while (i <= n)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            int t = st.top();
            int h = a[t];
            st.pop();
            if (st.empty())
            {
                ans = max(ans, h * i);
            }
            else
            {
                int len = i - st.top() - 1;
                ans = max(ans, h * len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

signed main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }

    cout << LargestRectangle(a, n) << endl;

    return 0;
}
