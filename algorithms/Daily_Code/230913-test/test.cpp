#include <stdio.h>
#include <string.h>
#include <windows.h>
int main()
{
	int i = 0;
	char bar[102];
	memset(bar, 0, sizeof(bar));
	const char* lable = "|/-\\";
	while (i <= 100) {
		printf("[%-100s][%d%%][%c]\r", bar, i, lable[i % 4]);
		fflush(stdout);
		bar[i++] = '#';
		Sleep(100);
	}
	printf("\n");
	return 0;
}