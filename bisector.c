/*Author: pygav
  Date: 8/23/2022
  Instructor: me
*/

/*Program description: Find the perpendicular bisector between two sets of points defined by user input, then display the calculation in slope-intercept form */

#include <stdlib.h>         /*include standard library and standard inputs and outputs */
#include <stdio.h>

int main()

{

    double x1, x2, y1, y2, x_mid, y_mid,            /*define variables being used to make the calculation */
            slope_segment, slope_mid, y_mid_interc;

    printf("Enter in the x-coordinate for first set of points =>");
    scanf("%lf", &x1);

    printf("\nEnter in the y-coordinate for first set of points =>");       /*ask the user to give two sets of coordinates to use for calculations */
    scanf("%lf", &y1);

    printf("\nEnter in the x-coordinate for second set of points =>");
    scanf("%lf", &x2);

    printf("\nEnter in the y-coordinate for second set of points =>");
    scanf("%lf", &y2);

    slope_segment = (y2 - y1) / (x2 - x1); /*calculate the slope of the line segment provided by the user */

    x_mid = (x1 + x2) / 2.0;
                                            /*calculate the coordinates of the mid-poiunt for the perpendicular bisector */
    y_mid = (y1 + y2) / 2.0;

    slope_mid = -1.0 / slope_segment;       /*calculate the slope of the perpendicular bisector */

    y_mid_interc = y_mid - (slope_mid * x_mid); /*calculate the y-intercept of the perpendicular bisector */

    printf("\nThe y-intercept formula for the perpendicular bisect is:\n y = (%.1lf)x + %.2lf", slope_mid, y_mid_interc);


    return(0);
}
