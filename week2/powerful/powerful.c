/* file:        powerful.c                                          */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        19-09-2016                                          */
/* version:     2.0.0                                               */
/* description: This program prints the nth number with a narcissistic property.  */

// Includes libraries for functionalities
#include <stdio.h>

int power(int a, int b) { //Simple power function
     int pow;
     int i;
     pow = 1;
     i = 0;
     while(i < b) {
          pow = pow*a;
          i++;
     }

     return pow;
}
 
int main(int argc, char *argv[]) {
    int x;          // input value
    int i;          // Determines of how many numbers the input consists     
    int temp, t, y; // Holds values temporarily so they can be worked with and will not be lost
    int n;
    int count;      // Value that holds the number of the narcissistic number found
    int sum;        // Holds the value to be tested whether it is a narcissistic number or not

    scanf("%d", &x);
    n = 1;

    label: // Label from line 47
    i = 0;
    temp = n;
    t = n;
    sum = 0;
    while(t != 0) { // Determines length of given number
        t /= 10;
        i++;
    }
    while(temp != 0) { // Determines the property of a narcissistic number to be tested
        y = temp%10;
        sum = sum + power(y, i);
        temp = temp/10;
    }

    if(sum == n) { // If the if-statement is met add one to the count of narcissistic numbers found
        count++;
        if(count == x) { // Determines whether the found narcissistic number is the required one
            printf("%d\n", n);
            return 0;
        }
    }
    n++;
    goto label; // Sorry
}