#include <math.h>
double calc ( double x , double y , double z ) {
	double a;
	if ((x-y!=0) && (z!=0) && (x!=0) && (sin(y)!=0)) {
a=pow(x,y+1)/pow(x-y,1/z)+z/x+sqrt(abs(cos(y)/sin(x)+1));
return a;
}
else {
	return NAN;
}
}