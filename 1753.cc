#include<cstdio>
#include<algorithm>

char board[5][5];

int another_board[5][5];

int dx[5] = {1, 0, -1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};

void print_board() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d", another_board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%s", board[i]);
    }
    
    int ans = 17;

    for (int bits = 0; bits < (1<<16); bits++) {
        int bits_copy = bits;

        for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            another_board[i][j] = board[i][j] == 'w' ? 1 : 0;
        }

        for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            int flip = bits_copy & 1;
            bits_copy >>= 1;
            if (!flip) {
                continue;
            }

            for (int dd = 0; dd < 5; dd++) {
                int ii = i + dx[dd];
                int jj = j + dy[dd];

                if (ii < 0 || ii > 3 || jj < 0 || jj > 3) {
                    continue;
                } 
                
                another_board[ii][jj] ^= 1;
            }
        }

        int w = 1, b = 1;

        for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            w &= another_board[i][j];
            b &= 1^another_board[i][j];
        }

        if (w || b) {
            ans = std::min(ans, __builtin_popcount(bits));
        }
    }

    if (ans > 16) {
        printf("Impossible\n");
    } else {
        printf("%d\n", ans);
    }
}