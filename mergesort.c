#include <stdio.h>

void merge(int arr[], int start, int mean, int end)
{
	int merged[10], l1[10], l2[10];
	int i,j,k,len1, len2;
	len1 = 0;
	len2 = 0;
	for(i=start; i<=mean; i++)
	{
		l1[i-start] = arr[i];
		len1++;
	}
	for(j=mean+1;j<=end;j++)
	{
		l2[j-(mean+1)] = arr[j];
		len2++;
	}
	i = 0;
	j = 0;
	k = 0;
	while(len1 > 0 && len2 > 0){
		if(l1[i] < l2[j])
		{
			merged[k] = l1[i];
			i++;
			k++;
			len1--;
		}
		else{
			merged[k] = l2[j];
			j++;
			k++;
			len2--;
		}	
	}
	if(len1 == 0)
	{
		while(len2 > 0)
		{
			merged[k] = l2[j];
			k++;
			j++;
			len2--;
		}
	}
	else
	{
		while(len1 > 0)
		{
			merged[k] = l1[i];
			k++;
			i++;
			len1--;
		}
	}
	for(i=0;i<k;i++)
	{
		arr[start + i] = merged[i];
	}
	
}

void mergeSort(int arr[], int start, int end){
	
	int mean;
	
	if(start < end)
	{
		mean = start + ((end - start)/2);
		mergeSort(arr, start, mean);
		mergeSort(arr, mean+1, end);
		merge(arr, start, mean, end);

	}
	else{
	}
}

int main(){
	int array[10];
	int i;
	for(i=0;i<10;i++)
	{
		scanf("%d", &array[i]);
	}
	printf("\n");
	mergeSort(array, 0, 9);
	for(i=0;i<10;i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
