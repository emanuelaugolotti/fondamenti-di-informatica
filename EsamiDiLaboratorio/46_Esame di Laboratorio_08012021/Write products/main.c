#define _CRT_SECURE_NO_WARNINGS
#include "product.h"

int main(void)
{
	FILE* f = fopen("prova.txt", "w");
	if (f == NULL) {
		return NULL;
	}
	struct product lis[] = { {"289347", "Pizza Margherita", 6}, { "67832", "Chicken Nuggets", 5 }, 
	{"563454", "Pizza Quattro Stagioni", 7} };

	write_products(f, lis, 3);
	return 0;
}