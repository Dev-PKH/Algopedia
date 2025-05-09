#include <stdio.h>

int main(void) {
	int n ,m;
	int arr[100027];
	long long sum=0, max =0;
	
	scanf("%d%d",&n,&m);
	
	for(int i=0; i<n; i++) scanf("%d",&arr[i]);
	
	for(int i=0; i<m; i++) sum += arr[i];
	
	max = sum;
	
	for(int i=0; i< n-m; i++)
	{
		sum -= arr[i];
		sum += arr[i+m];
		if(max < sum) max = sum;
	}
	
	printf("%lld",max);
	
	return 0;
}
