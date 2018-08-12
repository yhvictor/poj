#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int calc(int n, int d) {
    vector<pair<int, int> > pos;
    int impossible = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        impossible = y > d;
        pos.push_back(make_pair(x, y));
    }
    
    if (impossible) {
        return -1;
    }

    sort(pos.begin(), pos.end());

    pair<int, int> previous_point = pos[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        int px = d * d - previous_point.second * previous_point.second;
        int nx = d * d - pos[i].second * pos[i].second;
        double pxs = sqrt(px);
        double nxs = sqrt(nx);
        if (previous_point.first + pxs < pos[i].first - nxs) {
            ans++;
            previous_point = pos[i];
        }
        if (previous_point.first + pxs > pos[i].first + nxs)  {
            previous_point = pos[i];
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    int cas=1, n, d;
    while(cin >> n) {
        cin >> d;
        
        if (n == 0 && d == 0) {
            return 0;
        }

        cout << "Case " << cas++ << ": " << calc(n, d) << endl;
    }
}