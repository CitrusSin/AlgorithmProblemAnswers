#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const char num_graph[10][7][8] = {
    {
        "0000000",
        "0.....0",
        "0.....0",
        "0.....0",
        "0.....0",
        "0.....0",
        "0000000",
    },
    {
        "......1",
        "......1",
        "......1",
        "......1",
        "......1",
        "......1",
        "......1",
    },
    {
        "2222222",
        "......2",
        "......2",
        "2222222",
        "2......",
        "2......",
        "2222222",
    },
    {
        "3333333",
        "......3",
        "......3",
        "3333333",
        "......3",
        "......3",
        "3333333",
    },
    {
        "4.....4",
        "4.....4",
        "4.....4",
        "4444444",
        "......4",
        "......4",
        "......4",
    },
    {
        "5555555",
        "5......",
        "5......",
        "5555555",
        "......5",
        "......5",
        "5555555",
    },
    {
        "6666666",
        "6......",
        "6......",
        "6666666",
        "6.....6",
        "6.....6",
        "6666666",
    },
    {
        "7777777",
        "......7",
        "......7",
        "......7",
        "......7",
        "......7",
        "......7",
    },
    {
        "8888888",
        "8.....8",
        "8.....8",
        "8888888",
        "8.....8",
        "8.....8",
        "8888888",
    },
    {
        "9999999",
        "9.....9",
        "9.....9",
        "9999999",
        "......9",
        "......9",
        "9999999",
    },
};

const char num_graph_small[10][5][6] = {
    {
        "00000",
        "0...0",
        "0...0",
        "0...0",
        "00000",
    },
    {
        "....1",
        "....1",
        "....1",
        "....1",
        "....1",
    },
    {
        "22222",
        "....2",
        "22222",
        "2....",
        "22222",
    },
    {
        "33333",
        "....3",
        "33333",
        "....3",
        "33333",
    },
    {
        "4...4",
        "4...4",
        "44444",
        "....4",
        "....4",
    },
    {
        "55555",
        "5....",
        "55555",
        "....5",
        "55555",
    },
    {
        "66666",
        "6....",
        "66666",
        "6...6",
        "66666",
    },
    {
        "77777",
        "....7",
        "....7",
        "....7",
        "....7",
    },
    {
        "88888",
        "8...8",
        "88888",
        "8...8",
        "88888",
    },
    {
        "99999",
        "9...9",
        "99999",
        "....9",
        "99999",
    },
};

const char inf_graph[7][24] = {
    "IIIIIII.N.....N.FFFFFFF",
    "...I....NN....N.F......",
    "...I....N.N...N.F......",
    "...I....N..N..N.FFFFFFF",
    "...I....N...N.N.F......",
    "...I....N....NN.F......",
    "IIIIIII.N.....N.F......"
};

i64 qpow(i64 base, i64 exp, i64 lim, bool &of)
{
    __int128 r = base, rst = 1;
    while (exp)
    {
        if (r > lim)
        {
            of = true;
            return 0;
        }
        if (exp & 1)
        {
            rst *= r;
            if (rst > lim)
            {
                of = true;
                return 0;
            }
        }
        r *= r;
        exp >>= 1;
    }
    return rst;
}

void insert_num_graph(vector<vector<char>> &mat, char ch)
{
    int sidx = mat.size() + 1;
    for (int i = 0; i < 8; i++)
    {
        mat.push_back(vector<char>(10, '.'));
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            mat[sidx + i][2 + j] = num_graph[ch - '0'][j][i];
        }
    }
}

void insert_upper_num_graph(vector<vector<char>> &mat, char ch)
{
    int sidx = mat.size() + 1;
    for (int i = 0; i < 6; i++)
    {
        mat.push_back(vector<char>(10, '.'));
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mat[sidx + i][1 + j] = num_graph_small[ch - '0'][j][i];
        }
    }
}

void insert_equal_graph(vector<vector<char>> &mat)
{
    int sidx = mat.size() + 1;
    for (int i = 0; i < 8; i++)
    {
        mat.push_back(vector<char>(10, '.'));
    }
    for (int i = 0; i < 7; i++)
    {
        mat[sidx + i][4] = mat[sidx + i][6] = '=';
    }
}

void insert_inf_graph(vector<vector<char>> &mat)
{
    int sidx = mat.size() + 1;
    for (int i = 0; i < 24; i++)
    {
        mat.push_back(vector<char>(10, '.'));
    }
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            mat[sidx + i][2 + j] = inf_graph[j][i];
        }
    }
}

void solve()
{
    const i64 lim = 1e18;

    i64 x, y;
    scanf("%lld^{%lld}", &x, &y);
    bool inf_flag = false;
    i64 z = qpow(x, y, lim, inf_flag);

    vector<vector<char>> result;

    stringstream ss1;
    ss1 << x;
    string s1 = ss1.str();

    stringstream ss2;
    ss2 << y;
    string s2 = ss2.str();

    for (char c : s1)
    {
        insert_num_graph(result, c);
    }
    for (char c : s2)
    {
        insert_upper_num_graph(result, c);
    }
    insert_equal_graph(result);

    if (inf_flag)
    {
        insert_inf_graph(result);
    }
    else
    {
        stringstream ss3;
        ss3 << z;
        string s3 = ss3.str();

        for (char c : s3)
        {
            insert_num_graph(result, c);
        }
    }

    result.push_back(vector<char>(10, '.'));

    int n = 10, m = result.size();
    for (int i = 0; i < n; i++)
    {
        stringstream ss;
        for (int j = 0; j < m; j++)
        {
            ss << result[j][i];
        }
        string sp = ss.str();
        printf("%s\n", sp.c_str());
    }
    putchar('\n');
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        solve();
    }
    return 0;
}