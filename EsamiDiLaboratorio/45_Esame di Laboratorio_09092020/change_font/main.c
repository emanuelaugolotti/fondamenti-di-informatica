#include <stdlib.h>
extern char* change_font(const char* s);

int main(void)
{
	char* ris;
	ris = change_font("QUATTRO PAPERE VISITARONO SEI MUSEI");
	free(ris);
	
	return 0;
}