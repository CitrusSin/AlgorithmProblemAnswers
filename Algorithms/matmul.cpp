#include <functional>
#include <iostream>
#include <limits>
#include <vector>
#include <utility>
#include <memory>

using namespace std;

int64_t arrange(const vector<pair<int, int>>& shapes, vector<int>& suffix_sequence) {
    struct ast {
        int64_t node;
        pair<int64_t, int64_t> left, right;

        ast(int64_t id) : node(id), left(-1, -1), right(-1, -1) {}
    };

    size_t n = shapes.size();

    vector<vector<int64_t>> dp(n, vector<int64_t>(n, numeric_limits<int64_t>::max()));
    vector<vector<ast>> asts(n, vector<ast>(n, ast(-1)));

    for (size_t i=0; i<n; i++) {
        dp[i][i] = 0;
        asts[i][i].node = i;
    }

    // dp[i][j] = min(k in (i, j-1)){dp[i][k]+dp[k+1][j]+shapes[k].second * shapes[i].first * shapes[j].second}
    for (size_t d=2; d<=n; d++) {
        for (size_t i=0; i<n-d+1; i++) {
            size_t j = i+d-1;
            for (size_t k=i; k<j; k++) {
                int64_t time = dp[i][k] + dp[k+1][j] + shapes[k].second * shapes[i].first * shapes[j].second;
                if (time < dp[i][j]) {
                    dp[i][j] = time;
                    asts[i][j].left = make_pair(i, k);
                    asts[i][j].right = make_pair(k+1, j);
                }
            }
        }
    }

    suffix_sequence.clear();
    suffix_sequence.reserve(2 * n - 1);
    function<void(ast&)> genseq = [&](ast& t) {
        if (t.node >= 0) {
            suffix_sequence.push_back(t.node);
            return;
        }
        genseq(asts[t.left.first][t.left.second]);
        genseq(asts[t.right.first][t.right.second]);
        suffix_sequence.push_back(-1);
    };
    genseq(asts[0][n-1]);

    return dp[0][n-1];
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> shapes(n);
    for (int i=0; i<n; i++) {
        cin >> shapes[i].first >> shapes[i].second;
    }

    vector<int> sequence;
    int64_t ans = arrange(shapes, sequence);
    for (int i : sequence) {
        cout << i << ' ';
    }
    cout << '\n';

    cout << "Final: " << ans << '\n';
}