/*Author: pygav
  Date: 8/28/2022
  Instructor: me
*/

/*Program description: A hardware company that manufactures flat washers needs to know the weight of washers after manufacturing for shipping costs.
They also need to know how much leftover material they have after manufacturing. This program calculates these values given the user input of the outer diameter
of the washer, the inner diameter of the washer's hole, the thickness of the material, and the density of the material.

**NOTE** To make this program more of a real world scenario, I have made it that the sheet material being manufactured is configured in a way that washers are manufactured
200 per sheet, with 1 cm of spacing between each washer, and a 2 cm spacing between top and bottom of the sheet. The length and width of the sheet is contingent upon the size of the washer */



#include <stdio.h>      /*include standard library and standard inputs and outputs */
#include <stdlib.h>

#define PI 3.14159
                                    /*Define the constants of pi and how many washers are manufactured per sheet */
#define WASHERS_PER_SHEET 200

int main(void){

    int washers;

    double mat_total, additional_washers, additional_washers_area, additional_washers_weight, mat_thickness, mat_density, outer_dia,
        inner_dia, mat_length, mat_width, mat_area, washer_area, mat_weight, washer_weight,       /*define all variables used in calculating */
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

    mat_width = (outer_dia * WASHERS_PER_SHEET) + 100.0;

    mat_length = outer_dia + 4.0;           /*calculate the area of a sheet used based on the size of the washer */

    mat_area = mat_width * mat_length;

    mat_total = (double)(washers / WASHERS_PER_SHEET);

    additional_washers = (double)(washers % WASHERS_PER_SHEET);     /*find out how many washers are leftover that don't fit on a sheet of 200 */

    outer_dia = outer_dia / 2.0;

    inner_dia = inner_dia / 2.0;

    washer_area = (PI * outer_dia * outer_dia) - (PI * inner_dia * inner_dia); /*calculate the rim area of the washer */

    additional_washers_area = mat_area - (washer_area * additional_washers);
                                                                            /*calculate the area of the additional material needed to manufacture the washers */
    additional_washers_area = mat_area - additional_washers_area;

    mat_area = (mat_area * mat_total);      /*calculate the total area of the sheets used */

    mat_area = mat_area + additional_washers_area;

    additional_washers_weight = additional_washers_area * mat_thickness * mat_density; /*calculate the weight of the additional material needed */

    washer_weight = washer_area * mat_thickness * mat_density;

    washer_weight = washer_weight * washers;    /*calculate the total weight of washers and material, adding the additional resources needed for washers that won't fit on a sheet of 200 */

    washer_area = washer_area * washers;

    mat_weight = mat_area * mat_thickness * mat_density;

    leftover_mat_area = (mat_area - washer_area) + additional_washers_area;

    leftover_mat_weight = (mat_weight - washer_weight) + additional_washers_weight;

    printf("\nThe weight of the total washers would be %.2lf grams, the left over material area would be %.2lf sq cm, \nand the leftover material weight would be %.2lf grams", washer_weight, leftover_mat_area, leftover_mat_weight);

    return (0);
}
