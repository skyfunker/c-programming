/**
Zadanie 4.3 
*/
#include <stdio.h>
// #include <stdlib.h>

#define FILE_IN "tovary.dat"
#define MAX_COUNT 20

struct data {int d, m, r;};
struct towar {
	char nazwa[30];
	float cena;
	struct data data_prod;
};
struct towar makeTowar(char *name, float price, struct data date) {
    struct towar t;
    strcpy(t.nazwa, name);
    t.cena = price;
    t.data_prod.d = date.d;
    t.data_prod.m = date.m;
    t.data_prod.r = date.r;
    return t;
}

struct data makeDate(int day, int month, int year) {
    struct data temp;
    temp.d = day;
    temp.m = month;
    temp.r = year;
    return temp;
}

void printTowar(struct towar t) {
    printf("Towar: %s\n", t.nazwa);
    return; 
}

int sortByName (const void * a, const void * b) {
    return strcmp (((struct towar *)a)->nazwa, ((struct towar *)b)->nazwa) > 0;
}
       
int main(int argc, char **argv) {
    char *sortby;
	struct towar spis_towarow[MAX_COUNT];
	
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
	
	int cnt, i = 0;
   	int day, month, year;
   	struct towar t;
	while(fgets(line, sizeof(line), fIn) != NULL) {
	    cnt = sscanf(line, "%[^';'];%f;%[^';']", title, &price, date);
		if( cnt == 3) {
            printf("Title: %s, Price: %f, Date: %s ", title, price, date);
            sscanf(date, "%d-%d-%d", &day, &month, &year);
            printf("%d/%d/%d\n", month, day, year);
            spis_towarow[i] = makeTowar(title, price, makeDate(day, month, year));
            ++i;
		} else {
			printf("Data reading error. Skip the line.\n");
		}
	}
	fclose(fIn);

//     qsort (spis_towarow, MAX_COUNT, sizeof(struct towar), sortByName);
    

	int k;
    for(k = 0; k < i; k++) {
        printTowar(spis_towarow[k]);
    }        
	return 0;
}

