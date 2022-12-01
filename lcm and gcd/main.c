#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int lcm;
	int gcd;
}lg;

lg lcmAndGcd(int a, int b){
	int start;
	if(a>b){
		start = b;
	}else{
		start = a;
	}
	int gcd = 1;
	for(int i = start;i>=2;i--){
		if(a%i == 0 && b%i == 0){
			gcd = i;
			break;
		}
	}
	
	int lcm = a*b/gcd;
	lg value;
	value.lcm = lcm;
	value.gcd = gcd;
return value;
}

int main(int argc,char** argv){
	if(argc < 3){
		printf("Please input atleast 2 numbers.\n");
		printf("Example: %s 5 6 7 8 9 10\n",argv[0]);
		return 0;
	}
	int numList[argc-1];
	int wrongInput = 0;
	printf("Your inputs are:");
	for(int i=0;i<=(argc-2);i++){
		numList[i] = atoi(argv[i+1]);
		printf(" %d",numList[i]);
		if(numList[i]<1){
			wrongInput = 1;
		}
		
	}
	printf("\n");

	if(wrongInput == 1){
		printf("Wrong input. Please input numbers greater then or equal 1\n");
		return 0;
	}

	lg value = lcmAndGcd(numList[0],numList[1]);
	for(int i=2;i<=(argc-2);i++){
		printf("calculation: %d\n",numList[i]);
		value.lcm = lcmAndGcd(value.lcm,numList[i]).lcm;
		value.gcd = lcmAndGcd(value.gcd,numList[i]).gcd;
	}
	
	printf("gcd = %d\n",value.gcd);
	printf("lcm = %d\n",value.lcm);
	return 0;
}
