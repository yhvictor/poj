#include<cstdio>
#include<iostream>

using namespace std;

char board[5][5];
int another_board[5][5];

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 4; i++) {
        cin >> board[i];
    }

    int ans = 17;
    int ans_bits;

    for (int bits = 0; bits < (1<<16); bits++) {
        int bits_copy = bits;

        for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            another_board[i][j] = board[i][j] == '-' ? 1 : 0;
        }

        for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            int flip = bits_copy & 1;
            bits_copy >>= 1;
            if (!flip) {
                continue;
            }

            for (int ii = 0; ii < 4; ii ++) {
                another_board[ii][j] ^= 1;
            }
            for (int jj = 0; jj < 4; jj ++) {
                another_board[i][jj] ^= 1;
            }
            another_board[i][j] ^= 1;
        }

        int all_open = 1;

        for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            all_open &= another_board[i][j];
        }

        if (all_open) {
            int ans_tmp = __builtin_popcount(bits);
            if (ans_tmp < ans) {
                ans = ans_tmp;
                ans_bits = bits;
            }
        }
    }

    printf("%d\n", ans);
    for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
        int flip = ans_bits & 1;
        ans_bits >>= 1;
        if (!flip) {
            continue;
        }
        printf("%d %d\n", i + 1, j + 1);
    }
}