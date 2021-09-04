#include <bits/stdc++.h>
#define Speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

int Rainwater(vector<int> &a, int n)
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
            ans += (min(a[i], a[st.top()]) - a[curr]) * diff;
        }
        st.push(i);
    }
    return ans;
}

signed main()
{
    Speed int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }

    cout << Rainwater(a, n) << endl;
    return 0;
}
