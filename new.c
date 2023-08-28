#include<stdio.h>
int main(){
    float arr[4];
    printf("Enter the values: ");
    for(int i=0; i<4; i++)scanf("%f",&arr[i]);
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<(int)arr[i]; k++){
                printf("%c  ",'*');
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}