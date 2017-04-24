/**
Zadanie 4.3 
*/
#include <stdio.h>
#include <stdlib.h>
#define FILE_IN "tovary.dat"

int main(int argc, char **argv)
{
	
	char *sortby;
	struct data {int d, m, r;};
	struct towar {
		char nazwa[30];
		float cena;
		struct data data_prod;
	};
	struct towar spis_towarow[1000];
	
	FILE *fIn;
	char line[80];
	char title[50];
	float price;
	char date[11];

	if(argc == 2) {
		sortby = argv[1]; 
	} else {
		// by default sort by name
		sortby = "-n";
	}
	
		
	fIn = fopen(FILE_IN, "rb");
	if(fIn == NULL) { 
		printf("Nie mozna otworzyc pliku %s\n", FILE_IN);
		return 1;
	}
	
	int cnt;
	while(fgets(line, sizeof(line), fIn) != NULL) {
		cnt = sscanf(line, "%s;%f;%s", title, &price, date);
		if( cnt == 3) {
			printf("Title: %s, Price: %f, Date: %s\n", title, price, date);
		} else {
			printf("sscanf error\n");
		}
	}

	fclose(fIn);
	return 0;
}

