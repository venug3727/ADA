#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int P[MAX_SIZE], Pi[MAX_SIZE], Dir[MAX_SIZE];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printPermutation(int n) {
    for (int i = 0; i < n; i++){
        printf("%d ", P[i]);
    }
    printf("\n");
}

void initialize(int n) {
    for (int i = 1; i < n; i++) {
        P[i] = i + 1;
        Pi[i] = i;
        Dir[i] = -1;
    }
}

int findMobile(int n) {
    int mobile = 0, mobilePos = -1;
    for (int i = 0; i < n; i++) {
        if ((Dir[i] == -1 && i > 0 && P[i] > P[i - 1] && P[i] > mobile) ||
            (Dir[i] == 1 && i < n - 1 && P[i] > P[i + 1] && P[i] > mobile)) {
            mobile = P[i];
            mobilePos = i;
        }
    }
    return mobilePos;
}

void johnsonTrotter(int n) {
    initialize(n);
    printPermutation(n);
    int mobile, mobilePos;
    while (true) {
        mobilePos = findMobile(n);
        if (mobilePos == -1) {
            break;
        } else {
            mobile = P[mobilePos];
            int newMobilePos = mobilePos + Dir[mobilePos];
            swap(&P[mobilePos], &P[newMobilePos]);
            swap(&Pi[P[mobilePos] - 1], &Pi[P[newMobilePos] - 1]);
            swap(&Dir[mobilePos], &Dir[newMobilePos]);
            for (int i = 0; i < n; i++) {
                if (P[i] > mobile) {
                    Dir[i] = -Dir[i];
                }
            }
            printPermutation(n);
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n (<= %d): ", MAX_SIZE);
    scanf("%d", &n);
    if (n > MAX_SIZE || n < 1) {
        printf("Invalid input.\n");
        return 1;
    }
    johnsonTrotter(n);
    return 0;
}
