#include <stdio.h>
#include <math.h>
unsigned long long factorial(int n) {
    if (n == 0) return 1;
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
int main() {
    int n ;
	printf("enter the number:");
	scanf("%d",&n); 
    unsigned long long total_keys = factorial(n);
    double approx_keys = log2(total_keys);
    printf("Total number of possible keys: %llu\n", total_keys);
    printf("Approximate power of 2: 2^%.2f\n", approx_keys);
    unsigned long long unique_keys = total_keys / (5 * 5);
    double approx_unique_keys = log2(unique_keys);
    printf("Approximate number of effectively unique keys: 2^%.2f\n", approx_unique_keys);
return 0;
}