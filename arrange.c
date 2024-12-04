#include <stdio.h>

void arrange(int *num1, int *num2, int *num3);
void swap(int* x, int* y);
 
int main(void){
    int num1, num2, num3;
    scanf("%d %d %d",&num1,&num2,&num3); //stores the 3 numbers in the order num1, num2, num3
    arrange(&num1, &num2, &num3);
    printf("\nSmallest: %d",num1); //displays the smallest number stored in num1
    printf("\nMiddle  : %d",num2); //displays the middle number stored in num2
    printf("\nLargest : %d",num3); //displys the largest number stored in num3
    return 0;
}

//code of arrange() here!
void arrange(int* num1, int* num2, int* num3) { 
    if (*num2 > *num3) {
        swap(num2, num3);
    } 
    if (*num1 > *num3) {
        swap(num1, num3);
    }
    if (*num1 > *num2) {
        swap(num1, num2);
    }
}

void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}