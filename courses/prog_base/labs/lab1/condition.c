int isPowerOfTwo (int number) {
    double power = log2(number);
    if (floor(power) == power) {
        return 1;
    } else {
        return 0;
    }
}//степінь 2ки
int satisfies ( int a , int b , int c ) {
	 int n0 = 0;
    int n1 = 1;
int result ;
int modmin, sum2;
if ((a<0) && (b<0) && (c<0)) {
	if ((a<b) && (a<c)) {
	modmin=abs(a);
	sum2=b+c;
}
	else {
		if ((b<a) && (b<c)) {
			modmin=abs(b);
			sum2=a+c;
		}
			else {
				modmin=abs(c);
				sum2=a+b;
			}
	}  //шукаємо суму інших двох чисел
	if ((sum2<-256) && (modmin<256) &&(isPowerOfTwo(modmin)==1) ){
		return 1;
	}
		else {
			if (abs(sum2-modmin)<16 || (abs(sum2)<16)) {
				return 1;
			}
			else{
				return 0;
			}
		}
}
else {
	if ((a<0) || (b<0) || (c<0)) {
		if ((a<0) && (b>=0) && (c>=0) || (a>=0) && (b<0) && (c>=0) || (a>=0) && (b>=0) && (c<0)){
			if (a<0) {
				return (a>-256);
			}
			if (b<0) {
				return (b>-256);
			}
			if (c<0) {
				return (c>-256);
			}
			else { 
				if (a>=0) {
					return (b+c)*(n0+n1)>-256;
				}
				if (b>=0) {
					return (a+c)*(n0+n1)>-256;
				}
				if (c>=0) {
					return (a+b)*(n0+n1)>-256;
				}	
			}	
		}
		else{
			int max;
			max = (a>b) ? a:b;
			max = (max>c) ? max:c;
			int min;
			min = (a<b) ? a:b;
			min = (min<c) ? min:c;	
			return (max-min>32);
		}
		
	}
	return 0;
}
return result ;
}