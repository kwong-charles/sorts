#include <stdlib.h>
#include <stdio.h>

int arr[10000];
int i, j, temp;

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
    for(i = 1 ; i < 10000 ; i++){
        temp = arr[i];
        j = i - 1;
        while(temp < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    for(i = 0; i < 10000 ; i++){
        printf("%d\t", arr[i]);
    }
    system("pause");
}