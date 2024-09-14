#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER1_SIZE 100
#define BUFFER2_SIZE 100

int main(int argc, char* argv[])
{
	if (argc != 2) {
		return 1;
	}
	FILE* f = fopen(argv[1], "r");
	if (f == NULL) {
		return 1;
	}
	char* buffer1 = NULL;

	for (size_t r = 0; r < 10; ++r) {

		int buffer1Size = BUFFER1_SIZE;
		buffer1 = calloc(buffer1Size, sizeof(char));
		char *ris = fgets(buffer1, buffer1Size, f);

		// termina con un a capo dopo aver letto tutto
		if (ris == NULL) {
			printf("\n");
			break;
		}

		// stampo il carattere a capo della riga precedentemente letta
		if (buffer1[0] == '\n') {
			printf("\n");
			continue;
		}

		int buffer2Letti = 0;

		// leggo tutta la riga eccetto il carattere a capo
		do  {
			char buffer2[BUFFER2_SIZE] = {0};
			fgets(buffer2, BUFFER2_SIZE, f);
			buffer2Letti = strlen(buffer2);
			buffer1Size += buffer2Letti; // non considero il + 1 del terminatore per via di strcat
			buffer1 = realloc(buffer1, buffer1Size);
			strcat(buffer1, buffer2);
		} while (buffer2Letti == (BUFFER2_SIZE - 1));
		
		// stampo la riga eccetto il carattere a capo
		printf("%s", buffer1);
	}

	fclose(f);
	free(buffer1);

	return 0;
}