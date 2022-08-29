/*Author: pygav
  Date: 8/28/2022
  Instructor: me
*/

/*Program description: A hardware company that manufactures flat washers needs to know the weight of washers after manufacturing for shipping costs.
They also need to know how much leftover material they have after manufacturing. This program calculates these values given the user input of the outer diameter
of the washer, the inner diameter of the washer's hole, the thickness of the material, and the density of the material.

**NOTE** To make this program more of a real world scenario, I have made it that the sheet material being manufactured is configured in a way that washers are manufactured
200 per sheet, with 1 cm of spacing between each washer, and a 2 cm spacing between top and bottom of the sheet. The length and width of the sheet is contingent upon the size of the washer */
 /* **REVISED PROGRAM. This program is a revised version of washers.c in this repository. I rewrote this program to use separate functions to do the calculations instead of
 doing all calculations within the main function. Each function does the calculation needed then returns the value calculated. */


#include <stdio.h>      /*include standard library and standard inputs and outputs */
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
                                    /*Define the constants of pi and how many washers are manufactured per sheet */
#define WASHERS_PER_SHEET 200.0

double find_mat_area(double w, int t);

double find_washer_area(double o, double i, int t);

double find_mat_weight(double a, double t, double d);

double find_washer_weight(double a, double t, double d);



int
main(void){

    int washers;

    double mat_thickness, mat_density, outer_dia,
        inner_dia, mat_area, washer_area, mat_weight, washer_weight,       /*define all variables used in calculating */
        leftover_mat_area, leftover_mat_weight;

    printf("Enter the outer diameter of the washer (cm) =>");
    scanf("%lf", &outer_dia);

    printf("\nEnter the inner diameter of the washer hole (cm) =>");
    scanf("%lf", &inner_dia);

    printf("\nEnter the thickness of the washers (cm) =>");             /*prompt user to give information used in calculations */
    scanf("%lf", &mat_thickness);

    printf("\nEnter the density of the material (grams per cubic cm) =>");
    scanf("%lf", &mat_density);

    printf("\nEnter the number of washers in the batch =>");
    scanf("%d", &washers);

    mat_area = find_mat_area(outer_dia, washers);

    washer_area = find_washer_area(outer_dia, inner_dia, washers);

    washer_weight = find_washer_weight(washer_area, mat_thickness, mat_density);

    mat_weight = find_mat_weight(mat_area, mat_thickness, mat_density);

    leftover_mat_area = (mat_area - washer_area);

    leftover_mat_weight = (mat_weight - washer_weight);

    printf("\nThe weight of the total washers would be %.2lf grams, the left over material area would be %.2lf sq cm, \nand the leftover material weight would be %.2lf grams", washer_weight, leftover_mat_area, leftover_mat_weight);

    return (0);
}

/*Calculate the total area of the material needed

Pre: v is defined, t is defined */

double
find_mat_area(double w, int t){

    double l, area, sheets;

    sheets = (double)(t / WASHERS_PER_SHEET);

    sheets = ceil(sheets); /*Round up to the next sheet of material if amount of washers doesn't compute evenly to entire sheets */

    l = w + 4.0;

    w = (w * WASHERS_PER_SHEET) + 100.0;

    area = w * l;

    printf("%lf", area);

    area = (double)(area * sheets);

    return area;

}

/*Calculate the total rim area of the washers

Pre: o is defined, i is defined, t is defined */

double
find_washer_area(double o, double i, int t){

    double area;

    o = o / 2.0;

    i = i / 2.0;

    area = (PI * pow(o, 2)) - (PI * pow(i, 2));

    printf("%lf\n", area);

    area = (double)(area * t);

    return area;

}

/* Calculate the total weight of the material needed

Pre: a is defined, t is defined, d is defined */

double
find_mat_weight(double a, double t, double d){

    double mat_weight;

    mat_weight = a * t * d;

    return mat_weight;

}

/* Calculate the total weight of the washers given

Pre: a is defined, t is defined, d is defined */

double
find_washer_weight(double a, double t, double d){

    double washer_weight;

    washer_weight = a * t * d;

    return washer_weight;

}


