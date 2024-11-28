/// Rotational donut
/// 11|28|2024

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int k;

int main() {
    float A = 0, B = 0, i, j, z[1760];
    char b[1760];

    printf("\x1b[2J");
    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; j < 6.28; j += 0.005) {
            for (i = 0; i < 6.28; i += 0.04) {
                float c = sin(i), d = cos(j), e = sin(A), f = sin(j), g = cos(A),
                      h = d + 2, D = 1 / (c * h * e + f * g + 5), l = cos(i),
                      m = cos(B), n = sin(B),
                      t = c * h * g - f * e;

                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                N = N > 0 ? (N < 11 ? N : 11) : 0;

                if (o >= 0 && o < 1760 && 22 > y && y > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N];
                }
            }
        }
        printf("\x1b[H");
        for (k = 0; k < 1761; k++)
            putchar(k % 80 ? b[k] : 10);
        A += 0.04;
        B += 0.02;
        usleep(30000);
    }
}
