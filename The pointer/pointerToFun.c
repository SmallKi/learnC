#include <stdio.h>
int findMax(int *arr, int n){
	int max = arr[0];
	int i;
	for(i=0;i<n;i++){
		if(max<arr[i]){
			max = arr[i];
		}
	}
	
	return max;
}

int main(void){
	int a[] = {1,23,4,5};
	int len = sizeof(a)/sizeof(int);
	findMax(a,len);
	printf("The function is %p\n",findMax); //00000000004014F0
	int (*px)(int *,int) = findMax;
	printf("The pointer is %p",px);  //00000000004014F0
	//pointer to function is equal to function itself;
	//it's said that function name is actually a address;
}
