#include "angoli.h"

int main(void)
{
	struct angolo a = { 230, 23, 4 };
	struct angolo b = { 45, 47, 12 };
	struct angolo d;
	d = differenza_angoli(a, b);

	struct angolo a1 = { 10, 10, 10 };
	struct angolo b1 = { 10, 11, 11 };
	d = differenza_angoli(a1, b1);

	return 0;
}