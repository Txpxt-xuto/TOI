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
    int Fixed_cost,Variable_cost,profit,income,Total_cost,Number_of_books_sold,Selling_price_per_book,Number_of_prints,D;
    scanf("%d",&Fixed_cost);
    for(Number_of_prints=1000;Number_of_prints<=15000;Number_of_prints+=500)
    {
        for(Selling_price_per_book=74;Selling_price_per_book<=114;Selling_price_per_book++)
        {
            Variable_cost = Number_of_prints + (102 - (Number_of_prints/500));
            Total_cost = Fixed_cost + Variable_cost;
            D = Selling_price_per_book-100;
            Number_of_books_sold =  ((100 - (0.8569 * exp(0.09*D))) * จํานวนหนังสือที่พิมพ์ ) / 100
        }
    }

}