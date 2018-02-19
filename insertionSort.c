#include <stdio.h>

int main(){
	int i, j, key;
	int inputArray[10];
	for(i=0;i<10;i++)
	{
		scanf("%d",&inputArray[i]);
	}
	for(j=1;j<10;j++)
	{
		key = inputArray[j];
		i = j - 1;
		while(i >= 0 && inputArray[i] > key)
		{
			inputArray[i+1] = inputArray[i];
			i = i - 1;
		}
		inputArray[i+1] = key;
	}
	for(i=0;i<10;i++)
	{
		printf("%d ", inputArray[i]);
	}
	printf("\n");
	return 0;
}
