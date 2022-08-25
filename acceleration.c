/* Author: pygav
   Date: 8/24/2022
   Instructor: me
*/

/* Program description: Calculate the acceleration (m/s^2) of a fighter jet launched from an aircraft-carrier catapult, given the jets takeoff speed in km/hr
   and the distance (meters) over which the catapult accelerates the jet from rest to takeoff. Assume constant acceleration. Also calculate the time in seconds for the fighter jet
   from rest to takeoff */

#include <stdio.h>
#include <stdlib.h>





int main(void){

    double time, velocity, acceleration, distance;

    printf("What is the takeoff speed of the fighter jet? (in km/hr) =>");
    scanf("%lf", &velocity);

    printf("\nWhat is the distance at takeoff? (in meters) =>");
    scanf("%lf", &distance);

    velocity = velocity / 3.6;

    time  = distance / velocity;

    acceleration = velocity / time;

    printf("\nThe acceleration of the fighter jet would be : %.2lf m/s sq. and it would take %.2lf seconds to accelerate to takeoff", acceleration, time);



    return (0);
}
