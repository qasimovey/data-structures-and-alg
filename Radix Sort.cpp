#include <stdio.h>


int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(int arr[], int n, int exp){
    int output[n]; // output array
    int i, count[10] = {0};
 
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    for (i = 1; i < 10; i++) count[i] += count[i - 1]; 
	
	for (i = n - 1; i >= 0; i--)
    {	
    	// why -1 ? because indexing
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
		printf("%d-->%d,",i,(arr[i]/exp)%10);
    }
	printf("\n");
	
    for (i = 0; i < n; i++) arr[i] = output[i]; 
    
        for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
    
	} 


void radixsort(int arr[], int n) { 
	int m = getMax(arr, n);
	for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};

    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
		
	printf("\n");	
    radixsort(arr, n);
    for(int i = 0;i<n;i++)
	printf("%d ",arr[i]);
    return 0;
}
