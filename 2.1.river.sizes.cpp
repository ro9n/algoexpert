#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
typedef pair<int, int> ii;

vector<int> riverSizes(vector<vector<int>> mat) {
  // Write your code here.
  const ii d[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int n = mat.size(), m = mat[0].size();

  function<int(int, int)> dfs = [&](int i, int j) {
    int c = 1;
    for (int dd = 0; dd < 4; ++dd) {
      int ii = i + d[dd].ff, jj = j + d[dd].ss;
      if (ii < 0 || ii >= n || jj < 0 || jj >= m || !mat[ii][jj]) continue;
      else
        mat[ii][jj] = 0, c += dfs(ii, jj);
    }
    return c;
  };

  vector<int> r;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j]) mat[i][j] = 0, r.push_back(dfs(i, j));
    }
  }
  return r;
}
