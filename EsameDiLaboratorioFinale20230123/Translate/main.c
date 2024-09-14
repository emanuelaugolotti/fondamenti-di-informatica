extern void translate(char* str, const char* from, const char* to);

int main(void)
{
	char str[] = "ciao";
	translate(str, "abdc", "wxzy");
	
	return 0;
}