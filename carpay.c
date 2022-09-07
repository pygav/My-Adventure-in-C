#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double calculatePayment(double p, double i, double n);

int
main(void){

    int display_months;

    double price, down_payment, interest, months, monthly_pay;

    printf("Welcome to the monthly car payment calculator!");
    printf("\nWhat is the price of the car? =>");
    scanf("%lf", &price);
    printf("\nHow much money are you putting down on the car? =>");
    scanf("%lf", &down_payment);
    printf("\nWhat is the annual interest rate? =>");
    scanf("%lf", &interest);
    printf("\nHow many months will you be making payments? =>");
    scanf("%lf", &months);

    price = price - down_payment;

    monthly_pay = calculatePayment(price, interest, months);

    display_months = months;

    printf("\nCalculations completed... With a loan of $%.2lf, an annual interest rate of %.2lf percent over \n%d payment periods your monthly payment will be $%.2lf.", price, interest, display_months, monthly_pay);

    return(0);
}

double
calculatePayment(double p, double i, double n){

    double power, payment;

    i = (i * 100) / p;

    i = i / 12;

    i = i + 1.0;

    power = pow(i, -n);

    i = i - 1.0;

    power = 1.0 - power;

    payment = (i * p) / power;


    return payment;

}
