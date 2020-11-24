#include <stdio.h>
#include <stdlib.h>

int arr[10000];
int i, temp;
int flag = 1;

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
    do{
        flag = 1;
        for(i = 0; i <10000 ; i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = 0;
            }
        }
    }while(flag == 0);
    for(i = 0; i < 10000 ; i++){
        printf("%d\t", arr[i]);
    }
    system("pause");
}

