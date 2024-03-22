/*
TASK: ROI
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
#include <math.h>
int main()
{
    double Fixed_cost,Variable_cost,profit,income,Total_cost,Number_of_books_sold,Selling_price_per_book,Number_of_prints,D,min=9999999999999;
    double A,B,C;
    scanf("%lf",&Fixed_cost);
    for(Number_of_prints=1000;Number_of_prints<=15000;Number_of_prints+=500)
    {
        for(Selling_price_per_book=74;Selling_price_per_book<=144;Selling_price_per_book++)
        {
            Variable_cost = Number_of_prints + (100 - ((Number_of_prints-1000)/500));
            Total_cost = Fixed_cost + Variable_cost;
            D = Selling_price_per_book-100;
            Number_of_books_sold =  ((100 - (0.8569 * exp(0.09*D))) * Number_of_prints ) / 100;
            income = Number_of_books_sold * Selling_price_per_book;
            profit = income - Total_cost;
            printf("%f %f %f %f %f %f %f %f %f \n",Fixed_cost,Variable_cost,profit,income,Total_cost,Number_of_books_sold,Selling_price_per_book,Number_of_prints,D);
            /*if(profit >= 0 && min>profit)
            {
                min = profit;
                A = Number_of_prints;
                B = Selling_price_per_book;
                C = profit;
            }*/
        }
    }
    printf("%.0f %.0f %.2f",A,B,C);
}
