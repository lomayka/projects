#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
long long number;
short S,i,j;
double F=0,V,E=0;

printf("Enter the long long number ");
scanf("%lld", &number);

S=(number>>63)&1;
for (j=52;j<63;++j) {
        E+=((number>>j)&1)*(pow(2,(j-52)));
}

for (i=51;i>=0;--i) {
	F+=(((number>>i)&1)*(pow(2,i-52)));
}
if ((E==2047) && F!=0) {
printf("V=NaN");
}
if ((E==2047) && (F==0) && (S==1)) {
	printf("V=-Infinity");
	}
if ((E==2047) && (F==0) && (S==0)) {
	printf("V=Infinity");
	}
if ((E>0) && (E<2047)){
V=pow(-1,S)*pow(2,E-1023)*(1+F);
printf("V=%.325llf",V);
}
if ((E==0) && (F!=0)) {
	V=pow(-1,S)*pow(2,-1022)*F;
	printf("V=%.325llf",V);
}
if ((E==0) && (F==0) && (S==1)){
	V=-0;
	printf("V=%.325llf",V);
}
if ((E==0) && (F==0) && (S==0)){
	V=0;
	printf("V=%.325llf",V);
}
}

