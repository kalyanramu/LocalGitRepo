class Complex
{
private:
	double real, imaginary;
public:
	Complex(double x=0.0, double y=0.0):real(x),imaginary(y){};
	double re();
	double im();
	double mag();
	void operator+(const Complex& number);
	~Complex();
};