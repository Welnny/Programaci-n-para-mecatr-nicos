#include <stdio.h>
#include <stdlib.h>
double Suma(double a, double b);
double Div(double numerador,double denominador);
int main()
{
   double res2;
   double num1, num2, res;
   printf("\n Inserta el numero 1:");
   scanf("%lf", &num1);
   printf("\nInserta el numero 2:");
   scanf ("%lf", &num2);
   res = Suma(num1,num2);
   printf("\n Suma de %lf + %lf = %lf\n\n", num1, num2, res);
   res = Div2 (num1, num2, &res);
      printf("\n Division de %lf / lf = %lf\n\n", num1, num2, res2);

      return 0;
}
    double Suma(double a, double b)
{
    return a+b;

}
 double Div(double numerador, double denominador)
 {
  if(denominador == 0)
   {
       return 0;
   }else
     {
         return numerador/denominador;
     }
 }
     void Div2(double numerador, double denominador, double *result)
{
         if(denominador == 0)
     {
         return 0;
     }else
     {
         *result = numerador/denominador;
     }

}
