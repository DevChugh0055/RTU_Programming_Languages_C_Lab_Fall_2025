#include <stdio.h>

/*
    Task:
    Write a function `int sum_to_n(int n)` that computes
    the sum of all integers from 1 up to n using a for loop.

    In main():
      - Ask user for a positive integer n
      - If n < 1, print an error
      - Otherwise, call sum_to_n and print the result
*/

int is_prime(int n) {
  if (n <= 1) return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {
  int n;
  printf("Enter a positive integer n: ");
  scanf("%d", &n);

  if (n < 1) {
    printf("Error: n must be a positive integer.\n");
  } else {
    printf("Prime numbers up to %d are:\n", n);
    for (int i = 2; i <= n; i++) {
      if (is_prime(i)) {
        printf("%d ", i);
      }
    }
    printf("\n");
  }

  return 0;
}