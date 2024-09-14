#include <stdlib.h>
extern double entropia(const double* v, size_t n);

int main(void)
{
	double vector[5] = { 0.066667, 0.133333, 0.200000, 0.266667, 0.333333 };
	double entropiaRis = entropia(vector, 5);
	
	return 0;
}