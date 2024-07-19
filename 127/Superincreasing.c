#include <stdio.h>
#include <math.h>

#define MAX_N 200005
#define MOD 1000000007

long long int m[MAX_N];
long long int m2[MAX_N];
long long int dist[MAX_N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k, x;
        scanf("%d %d %d", &n, &k, &x);
        k--;
        if (k >= 30) {
            printf("NO\n");
            continue;
        }
        long long int minval = pow(2, k);
        if (x >= minval) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}