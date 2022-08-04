

#include "iter.hpp"

int main( void ) 
{
	int 	arr1[10] = {0,1,2,3,4,5,6,7,8,9};
	char	arr2[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	
	iter(arr1, 10, ptl);
	iter(arr2, 7, ptl);
	
	return (0);
}