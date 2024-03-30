#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T>
void scan(vector<T> &v) {for (T &x : v) cin >> x;}

inline int to_int(char c) {
    return c - '0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LUCHADOR
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int t;
    cin >> t;

    const int N = 13, M = 29;
    
    string days = "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|";
    string bars[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    map<string, int> bar_day;
    bar_day["Sun"] = 3;
    bar_day["Mon"] = 7;
    bar_day["Tue"] = 11;
    bar_day["Wed"] = 15;
    bar_day["Thu"] = 19;
    bar_day["Fri"] = 23;
    bar_day["Sat"] = 27;

    

    while (t--) {
        string date, bar;
        cin >> date >> bar;

        vector<vector<char>> calendar(N, vector<char>(M, ' '));
        for (int i = 0; i < M; ++i) {
            calendar[1][i] = days[i];
            calendar[0][i] = '-';
        }
        for (int i = 2; i < N; ++i) {
            if (! (i & 1)) for (int j = 0; j < M; ++j) {
                calendar[i][j] = '-';
            } else for (int j = 0; j < M; j += 4) {
                calendar[i][j] = '|';
            }
        }

        int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int day = to_int(date[0]) * 10 + to_int(date[1]);
        int mon = to_int(date[3]) * 10 + to_int(date[4]);
        int year = to_int(date[6]);
        year = year * 10 + to_int(date[7]);
        year = year * 10 + to_int(date[8]);
        year = year * 10 + to_int(date[9]);

        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            month_days[1] = 29;
        }

        // cout << day << " " << mon << " " << year << endl;

        int start_bar = bar_day[bar];
        int total_days = month_days[mon - 1];

        while (day != 1) {
            --day;
            start_bar -= 4;

            if (start_bar <= 0) {
                start_bar = 27;
            }
        }

        int i = 3, j = start_bar;
        while (day <= total_days) {

            if (day > 9) {
                calendar[i][j] = char('0' + day % 10);
                calendar[i][j - 1] = char('0' + day / 10);
            } else {
                calendar[i][j] = char('0' + day);
            }

            j += 4;
            if (j >= M) {
                j = 3;
                i += 2;

                if (i >= N) {
                    i = 3;
                }
            }

            ++day;
        }

        for (i = 3; i < N; i += 2) {
            for (j = 3; j < M; j += 4) {
                if (calendar[i][j] == ' ') {
                    calendar[i][j - 1] = '-';
                }
            }
        }

        calendar[0][0] = calendar[N - 1][0] = calendar[0][M - 1] = calendar[N - 1][M - 1] = '|';

        for (i = 0; i < N; ++i) {
            calendar[i][0] = calendar[i][M - 1] = '|';
            for (j = 0; j < M; ++j) {
                cout << calendar[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}