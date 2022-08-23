/*Author: py.gav
Date: 8/22/22
Instructor: me
*/

/*Program description: Calculate the installation costs and savings per day in liters if all the homes in a city were replaced
with a new economic toilet that used less than 1/5 of the amount of liters per flush */


#include <stdio.h>          /*include standard library and standard input and outputs*/
#include <stdlib.h>

#define PERSONS_PER_TOILET 3        /*define constants for toilet information */
#define FLUSHES_PER_DAY 14
#define OLD_TOILET_FLUSH_LITERS 15
#define NEW_TOILET_FLUSH_LITERS 2
#define NEW_TOILET_COST 150

int main (void) /*main function */

{
   int population, toilets, desired_days, flushes, total_toilet_cost, /*define the variables that will be manipulated during the course of the program */
        new_liters, old_liters, liters_per_day;




   printf("What is the population of the city? => "); /*prompt user to give the city population for calculating toilet cost*/

   scanf("%d", &population);  /*read the user input */

   printf("\nHow many days would you like to calculate? => "); /*prompt the user to give the range of days for calculating liter savings */

   scanf("%d", &desired_days);





   toilets = (int)(population / PERSONS_PER_TOILET); /*calculate the amount of toilets by taking the population and diving it by 3 for 3 persons per toilet */



    flushes = toilets * FLUSHES_PER_DAY; /*calculate total flushes for one day */



   old_liters = flushes * OLD_TOILET_FLUSH_LITERS; /*calculate how many liters the old toilet was using and what the new toilet will use for one day */

   new_liters = flushes * NEW_TOILET_FLUSH_LITERS;

   liters_per_day = desired_days * (old_liters - new_liters); /*calculate how many liters will be saved each day for the range provided */

   total_toilet_cost = toilets * NEW_TOILET_COST; /*calculate the toilet costs */




   printf("\nWith the population of %d people, in a range of %d days,\nThe total savings would be %d liters per day, and the cost to set up would be $%d", population, desired_days, liters_per_day, total_toilet_cost);










    return (0);

}
