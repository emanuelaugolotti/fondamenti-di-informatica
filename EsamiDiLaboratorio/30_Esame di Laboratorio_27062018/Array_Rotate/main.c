#include <stdlib.h>
extern int* rotate(const int* vec, size_t len, size_t r);

int main(void)
{
	int v[] = { 1, 2, 3, 4 };
	int* vRotate;
	
	vRotate = rotate(v, 4, 1);
	free(vRotate);
	
	vRotate = rotate(v, 4, 2);
	free(vRotate);
	
	vRotate = rotate(v, 4, 3);
	free(vRotate);
	
	vRotate = rotate(v, 4, 4);
	free(vRotate);
	
	vRotate = rotate(v, 4, 6);
	free(vRotate);
	
	vRotate = rotate(NULL, 4, 1);
	free(vRotate);

	return 0;
}