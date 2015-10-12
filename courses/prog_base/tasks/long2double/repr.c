/*#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double long2double (long long);
int main(){
long long number;
printf("%.325llf",long2double(number));
}*/
double long2double (long long number){
short S,i,j;
double F=0,V,E=0;
printf("Enter the long long number ");
scanf("%lli", &number);
S=(number>>63)&1;
for (j=52;j<63;++j) {
        E+=((number>>j)&1)*(pow(2,(j-52)));
}

for (i=51;i>=0;--i) {
	F+=(((number>>i)&1)*(pow(2,i-52)));
}
if ((E==2047) && F!=0) {
return NAN;
}
if ((E==2047) && (F==0) && (S==1)) {
	return -INFINITY;
	}
if ((E==2047) && (F==0) && (S==0)) {
	return INFINITY;
	}
if ((E>0) && (E<2047)){
V=pow(-1,S)*pow(2,E-1023)*(1+F);
return V;
}
if ((E==0) && (F!=0)) {
	V=pow(-1,S)*pow(2,-1022)*F;
	return V;
}
if ((E==0) && (F==0) && (S==1)){
	return -0;
}
if ((E==0) && (F==0) && (S==0)){
	return 0;
}
}
