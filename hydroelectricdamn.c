#include <stdio.h>
#include <stdlib.h>

#define WATER_GRAV_PULL 9.80

#define ELEC_EFFICIENCY .90


int main()

{
    double dam_height, cubic_meters_of_water;

    double water_mass;

    double work;

    double wattage;

    double megawattage;

    printf("Enter the height of the damn=>");
    scanf("%lf", &dam_height);
    printf("Enter the flow of water per second in cubic meters=>", &cubic_meters_of_water);
    scanf("%lf", &cubic_meters_of_water);

    water_mass = cubic_meters_of_water * 1000;

    work = water_mass * WATER_GRAV_PULL * dam_height;

    wattage = work * ELEC_EFFICIENCY;

    megawattage = wattage * (.000001);

    printf("\n The amount of megawatts produced with the information provided is: %.3lf MWs", megawattage);


    return(0);
}
