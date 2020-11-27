#include <stdlib.h>
#include <stdio.h>

int arr[10000];
int i;

void merge(int l, int m, int h){
    int n1 = m - l + 1;
    int n2 = h - m;
    int L[n1], R[n2];
    for(i = 0 ; i < n1 ; i++){
        L[i] = arr[l + i];
    }
    for(i = 0 ; i < n2 ; i++){
        R[i] = arr[m + 1 + i];
    }
    int j = 0, k = 0, i = 0;
    while(j < n1 && k < n2){
        if(L[j] > R[k]){
            arr[l + i] = R[k];
            k++;
        }
        else{
            arr[l + i] = L[j];
            j++;
        }
        i++;
    }
    while(j < n1){
        arr[l + i] = L[j];
        j++;
        i++;
    }
    while(k < n2){
        arr[l + i] = R[k];
        k++;
        i++;
    }
}

void mergesort(int l, int h){
    if (l < h) {
        int m = (l+h)/2;
        mergesort(l, m);
        mergesort(m + 1, h);
        merge(l, m, h);
    }
}

int main(){
    FILE *fp;
    fp = fopen("numbers (1).txt", "r");
    if(fp == NULL){ 
        printf("No file\n");
        system("pause");
        return 0;
    }
    for(i = 0 ; i < 10000 ; i++){
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    mergesort(0, sizeof(arr)/sizeof(arr[0]) - 1);
    for(i = 0; i < 10000 ; i++){
        printf("%d\t", arr[i]);
    }
    system("pause");
}