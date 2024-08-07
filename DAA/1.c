#include <stdio.h>
void merge(int arr[], int left, int mid, int right, int ascending) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0; 
    j = 0; 
    k = left;
    while (i < n1 && j < n2) {
        if (ascending) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        } else {
            if (L[i] >= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right, int ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }
}
void printArray(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++)
        printf("%d\n", arr[i]);
}
int main() {
    int n,i;
    printf("Enter number of times to reach destination: ");
    scanf("%d", &n);
    int times[n];
    printf("Enter time to reach destination:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &times[i]);
    }
    int choice;
    printf("Enter 1 for ascending order, 0 for descending order: ");
    scanf("%d", &choice);
    mergeSort(times, 0, n - 1, choice);
    printf("Sorted times:\n");
    printArray(times, n);
    return 0;
}

