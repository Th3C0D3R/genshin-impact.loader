/**
 * \brief   crypt
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#include <cstdio>
#include <cstdlib>

//--------------------------------------------------------------------------------------------------

#pragma comment(linker,"/ignore:4229")
#pragma comment(linker,"/ignore:4078")
#pragma comment(linker,"/ignore:4044")
#pragma comment(linker, "/MERGE:.rdata=.text")
#pragma optimize("gsy", on)

//--------------------------------------------------------------------------------------------------

static unsigned char key = 0xEE;

unsigned char lazy_xor(unsigned char c)
{
	return key ^ c;
}

//--------------------------------------------------------------------------------------------------

int main(int argc, char *argv[])
{

	char *arr_name;

	if (argc < 2) 
	{
		fprintf(stderr, "Usage: %s input_file [array_name] [> output_file]\n", argv[0]);
		return 1;
	}
	FILE* f = fopen(argv[1], "rb");
	if (f == NULL) 
	{
		fprintf(stderr, "%s: fopen(%s) failed", argv[0], argv[1]);
		return 1;
	}

	if (argc >= 3) 
	{
		arr_name = argv[2];
	}
	else
	{
		arr_name = "filedata";
	}
	printf("unsigned char %s[] = {", arr_name);

	long i;
	for (i = 0;; i++) 
	{
		int c = 0;
		if ((c = fgetc(f)) == EOF)
		{
			break;
		}
		if (i != 0)
		{
			printf(",");
		}
		if ((i % 12) == 0)
		{
			printf("\n\t");
		}
		printf("0x%.2X", lazy_xor((unsigned char)c));
	}

	printf("\n\t};\n");
	printf("unsigned long size = %i;", i);
	printf("unsigned char key = %i;", key);
	fclose(f);
	return 0;
}