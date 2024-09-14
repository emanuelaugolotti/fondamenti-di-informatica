#include <stdlib.h>

extern const void* memmem(const void* pagliaio, size_t psize, const void* ago, size_t asize);

int main(void)
{
	char buffer1[] = { 'c','e','r','c','a', ' ','6','a','b','e','r','o','a','g','o','l' };
	char buffer2[] = { 'a','g','o' };
	const char* ptr = memmem(buffer1, 16, buffer2, 3);
	
	return 0;
}