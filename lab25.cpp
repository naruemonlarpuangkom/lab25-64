#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		friend bool operator==(const ComplexNumber &,const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber operator+(double a,const ComplexNumber &c){
	return ComplexNumber(c.real+a,c.imag);
}

ComplexNumber operator-(double a,const ComplexNumber &c){
	return ComplexNumber(a-c.real,-c.imag);
}

ComplexNumber operator*(double a,const ComplexNumber &c){
	return ComplexNumber(c.real*a,c.imag*a);
}

ComplexNumber operator/(double a,const ComplexNumber &c){
	double x = (c.real*c.real)+(c.imag*c.imag);
	return ComplexNumber(a*c.real/x,a*(-c.imag)/x);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(real*c.imag)+(c.real*imag));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return (*this)*(1/c);
}

bool operator==(const ComplexNumber &c1,const ComplexNumber &c2){
	if(c1.real==c2.real && c1.imag==c2.imag) return true;
	else return false;
}

double ComplexNumber::abs(){
	return sqrt((real*real)+(imag*imag));
}

double ComplexNumber::angle(){
	return atan2(imag,real)*180/M_PI;
}

ostream & operator<<(ostream &os,const ComplexNumber &c){
	if(c.real==0 && c.imag==0) return os << "0";
	else if(c.imag==0) return os << c.real;
	else if(c.real==0) return os << c.imag << "i";
	else if(c.imag>0) return os << c.real << "+" << c.imag << "i";
	else return os << c.real << c.imag << "i";
	return os;
}
int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}