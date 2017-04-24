/**
Zadanie 4.1 Write a program that places several files in one file. 
The initial parameters used in the program call are to be the names of 
the files whose contents will be merged. 
The last parameter used in the call is to be the name of the file received 
after the content has been merged. If, for example, 
the compiled program was placed in a file named glue it after the call
Bonding list list list together

The program should create a file named together and list the contents 
of the files list, list, and list.

*/
#include <stdio.h>


int main(int argc, char **argv)
{
	FILE *fIn, *fOut;
	
	if(argc < 3) {
		printf("Not enough parameters. Usage: %s <inputfile1> <inputfile2> [inputN] <outputfile>\n\a", argv[0]);
        return 1;
	}
	
	fOut = fopen(argv[argc - 1], "wb");
    if(fOut == NULL){
        printf("Nie mozna otworzyc pliku %s\n\a", argv[argc - 1]);
        return 1;
    }
	
	int k;
	char c;
	for(k = 1; k < argc - 1; ++k) {
		
		fIn = fopen(argv[k], "rb");
		if(fIn == NULL) { 
			printf("Nie mozna otworzyc pliku %s\n", argv[k]);
		} else {
			printf("Dodanie pliku %s\n", argv[k]);
			while((c = fgetc(fIn)) != EOF) {
				fputc(c, fOut);
			}
			fclose(fIn);
		}
		
	} 
	
	
	fclose(fOut);
	return 0;
}

