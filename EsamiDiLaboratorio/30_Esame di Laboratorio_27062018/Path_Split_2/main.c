#include "path_split.h"

int main(void)
{
	char* pathOut;
	char* filenameOut;

	char str1[] = "c:\\user\\esami\\FdI2017\\esercizi";
	char str2[] = "c:\\user\\esami\\FdI2017\\esercizi\\file.txt";
	char str3[] = "esercizi\\";
	path_split(str1, &pathOut, &filenameOut);
	free(pathOut);
	free(filenameOut);

	path_split(str2, &pathOut, &filenameOut);
	free(pathOut);
	free(filenameOut);

	path_split(str3, &pathOut, &filenameOut);
	free(pathOut);
	free(filenameOut);

	path_split("", &pathOut, &filenameOut);
	free(pathOut);
	free(filenameOut);

	path_split("esercizi FdI2022", &pathOut, &filenameOut);
	free(pathOut);
	free(filenameOut);

	return 0;
}