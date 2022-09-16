#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159625
int
main(void){

    char shape;

    float value, s_area, c_area;


    printf("\nEnter the shape type you would like to calculate the area for ('S' for square and 'C' for circle) =>");
    scanf("%c", &shape);

    if (shape == 'S' || shape == 's'){
        printf("\nEnter the value of one side of the square =>");
        scanf("%f", &value);

        s_area = pow(value, 2);

        printf("\nThe area of the square is %f", s_area);
    }

    else if(shape == 'C' || shape == 'c'){
        printf("\nEnter the value of diameter of the circle =>");
        scanf("%f", &value);

        c_area = value / 2;

        c_area = PI * pow(c_area, 2);

        printf("\nThe area of the circle is %f", c_area);
    }

    else {
        printf("\nYou did not enter a valid shape type, please reload the program and try again...");
    }




    return (0);
}
