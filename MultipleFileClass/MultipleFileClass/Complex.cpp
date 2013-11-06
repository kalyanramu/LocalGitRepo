#include "Complex.h"
#include <math.h>

double Complex::re()
{
	return real;
}
double Complex::im()
{
	return imaginary;
}
double Complex::mag()
{
	return sqrt(real*real+imaginary*imaginary);
}
void Complex::operator+(const Complex& number)
{
	real+= number.real;
	imaginary+=number.imaginary;
}