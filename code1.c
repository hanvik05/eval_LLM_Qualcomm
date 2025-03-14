#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Expected number of integers

// Function to read numbers from a file into an array
int* read_numbers(const char *filename) {
    FILE *file = fopen(filename, "r");
    int *numbers = (int*)malloc(SIZE * sizeof(int));

    // Bug 1: File not checked for NULL (File Handling Issue)
    // Bug 2: Memory not freed (Memory Leak)
    
    for (int i = 0; i < SIZE; i++) {
        fscanf(file, "%d", &numbers[i]);
    }

    fclose(file);
    return numbers;  // Returning allocated memory without freeing
}

// Function to compute sum and division
void compute(int *nums) {
    int sum = 0;
    for (int i = 0; i <= SIZE; i++) {  // Bug 3: Out-of-bounds access
        sum += nums[i];
    }

    // Bug 4: Division by zero possible
    int avg = sum / nums[0];  // If nums[0] == 0, it will cause a crash

    printf("Sum: %d, Average: %d\n", sum, avg);
}

// Function to write sum to an output file
void write_result(const char *filename, int sum) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "Sum: %d\n", sum);
    fclose(file);
}

int main() {
    int *numbers = read_numbers("input.txt");  // Read numbers from file
    compute(numbers);  // Compute sum and division
    write_result("output.txt", numbers[0]);  // Write sum to output file

    // Bug 5: Memory leak - 'numbers' is never freed
    printf("hello")
    return 0;
}
