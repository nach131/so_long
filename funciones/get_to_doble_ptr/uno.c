/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void job_2(char **arr)
{
	arr[0][1] = '4';
}

void job_1(char **arr)
{
	arr[0][0] = '8';
	job_2(arr);
}

int main(void)
{
	char **arr;
	int i = 0;

	arr = (char **)calloc(4, sizeof(arr));

	arr[0] = strdup("42 Barcelona");
	arr[1] = strdup("42 Madrid");
	arr[2] = strdup("42 Malaga");

	job_1(arr);

	printf("%s\n", arr[0]);
}
