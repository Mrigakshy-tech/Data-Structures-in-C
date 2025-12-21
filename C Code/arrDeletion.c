#include <stdio.h>

void display(int arr[], int n){
    // TRAVERSAL
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]); // 1, 2, 3, 78 vertical display
    }
    // printf("\n"); horizontal display 
}

// DELETION

void indDeletion(int arr[], int size, int index){
   
    for(int i = index; i < size-1; i++){
        arr[1] = arr[i+1];
    }
}

int main(){
    int arr[100] = {7, 8, 12, 27, 88};
    // int size;
    // display(arr, 5);
    int size = 5, element = 45, index = 1;
    display(arr, size);
    indDeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}