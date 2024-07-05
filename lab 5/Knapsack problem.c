#include <stdio.h>
#include <time.h>
// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build K[][] table in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // K[n][W] contains the maximum value that can be obtained
    return K[n][W];
}

int main() {
    int val[100], wt[100]; // Arrays to store values and weights of items
    int W, n; // Knapsack capacity and number of items
    int i;

    // Input number of items and knapsack capacity
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    // Input values of items
    printf("Enter the values of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    // Input weights of items
    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
     clock_t start_time, end_time;
    double time_taken;

    start_time = clock();
    // Call the knapsack function and print the result
    printf("Maximum value that can be obtained: %d\n", knapsack(W, wt, val, n));
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);
    return 0;
}
