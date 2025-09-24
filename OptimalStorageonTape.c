#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int num;

    printf("Enter the number of files: ");
    scanf("%d", &num);

    int arr[num];

    for (int i = 0; i < num; i++) {
        printf("Enter the size of File %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    sort(arr, num);

    for (int i = 1; i < num; i++) {
        arr[i] = arr[i] + arr[i - 1];
    }

    float sum = 0;
    for (int i = 0; i < num; i++) {
        sum += arr[i];
    }

    printf("The Mean Retrieval Time is %.2f\n", sum / num);

    return 0;
}