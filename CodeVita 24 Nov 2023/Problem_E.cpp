// Accepted

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> cust;

    for (int i = 0; i < n; i++)
    {
        int q, p;
        cin >> q >> p;
        cust.push_back({p, q});
    }

    vector<vector<int>> rice;

    for (int i = 0; i < m; i++)
    {
        int q, p;
        cin >> q >> p;

        rice.push_back({p, q});
    }

    sort(cust.begin(), cust.end());
    sort(rice.begin(), rice.end());

    vector<int> vis(m, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int quantity = -1, ind = -1;
        for (int j = 0; j < m; j++)
        {
            if (!vis[j])
            {

                if (rice[j][0] > cust[i][0])
                    break;

                if (rice[j][1] > cust[i][1])
                {
                    if (quantity == -1)
                    {
                        quantity = rice[j][1];
                        ind = j;
                    }
                    else
                    {
                        if (quantity > rice[j][1])
                        {
                            ind = j;
                            quantity = rice[j][1];
                        }
                    }
                }
            }
        }

        if (ind != -1)
        {
            vis[ind] = 1;
            ans++;
        }
    }
    cout << ans;
}
