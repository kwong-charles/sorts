#include <stdio.h>
#include <stdlib.h>

int arr[100];
int key, i, place = -1;

int main(){
    FILE *fp;
    fp = fopen("numbers.txt", "r");
    if(fp == NULL){ 
        printf("No file\n");
        system("pause");
        return 0;
    }
    for(i = 0 ; i < 100; i++){
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    printf("enter search number thing");
    scanf("%d", &key);
    i = 0;
    while(i < sizeof(arr)/sizeof(arr[0])){
        if(arr[i] == key){
            place = i;
            break;
        }
        i++;
    }
    printf("%d", place);
    system("pause");
}