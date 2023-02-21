#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

void discPos (double, double, double);
void discNeg (double, double, double);
static double PI = 3.141592654;

int main(int argc, char *argv[]) {
	char *ptr = "\0";
	double a = strtod(argv[1], &ptr);
	double b = strtod(argv[2], &ptr);
	double c = strtod(argv[3], &ptr);
	double d = strtod(argv[4], &ptr);
	b = b/a;
	c = c/a;
	d = d/a;
	a = 1;
	double p = (3.0*c-pow(b,2))/3.0;
	double q = (2.0*pow(b,3)-9.0*b*c+27.0*d)/27.0;
	double discriminante = pow(q,2)+(4*pow(p,3))/27;
	if (discriminante > 0) discPos(discriminante, q, b);
	else if (discriminante == 0) {
		double z = -b/(3.0*a);
		if (p==0 and q==0) cout <<"{"<<z<<", "<<z<<", "<<z<<"}";
		else {
			double z1 = (3.0*q)/p;
			double z23 = -(3.0*q)/(2.0*p);
			cout <<"{"<<z1<<", "<<z23<<", "<<z23<<"}";
		}
	}
	else if (discriminante < 0) {
		//Formula de De Moivre
		discNeg(p, q, b);
	}
	else cout << "{}";
}

void discPos (double discriminante, double q, double b) {
	double u = pow((-q + sqrt(discriminante))/2.0, 1.0/3.0);
	double v = -pow((q + sqrt(discriminante))/2.0, 1.0/3.0);
	double z1 = u+v-(b/3);
	double zi = (sqrt(3.0)/2.0)*(u-v);
	double zr = -(1.0/2.0)*(u+v)-(b/3);
	cout << "{"<<z1<<", "<<zr<<"+"<<zi<<"i"<<", "<<zr<<"-"<<zi<<"i"<<"}";  
}

void discNeg(double p, double q, double b) {
	double deg = acos((3.0*q)/(2.0*p)*sqrt(-3.0/p));
	double z1 = 2.0*sqrt(-p/3.0)*cos(deg/3.0)-(b/3);
	double z2 = 2.0*sqrt(-p/3.0)*cos((deg+2.0*PI)/3.0)-(b/3);
	double z3 = 2.0*sqrt(-p/3.0)*cos((deg+4.0*PI)/3.0)-(b/3);
	cout <<"{"<<z1<<", "<<z2<<", "<<z3<<"}";
}
