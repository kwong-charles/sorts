#include <stdio.h>
#include <stdlib.h>

int key,arr[100];
int place = -1;

int main(){
    int i, l, h, m;
    FILE *fp;
    fp = fopen("numbers.txt", "r");
    if(fp == NULL){ 
        printf("No file\n");
        system("pause");
        return 0;
    }
    for(i = 0 ; i < 100 ; i++){
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    printf("enter search number thing");
    scanf("%d", &key);
    l = 0;
    h = sizeof(arr)/sizeof(arr[0]);
    m = (l+h)/2;
    while(place == -1 && h > l){
        if(key == arr[m]){
            place = m;
        }
        else if(key > arr[m]){
            l = m + 1;
        }
        else{
            h = m - 1;
        }
        m = (l+h)/2;
    }
    printf("%d", place);
    system("pause");
}