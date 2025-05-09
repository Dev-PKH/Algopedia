#include <iostream>
using namespace std;

int D(int num)
{
	int sum = num;
	while(num > 0)
	{
		sum += num %10;
		num /= 10;
	}
	
	return sum;
}

int main() {
	bool check[10001] = {false};
	
	for(int i=1; i<10001; i++)
	{
		check[D(i)] = true; 
		if(!check[i]) cout << i << '\n';
	}
	
	return 0;
}