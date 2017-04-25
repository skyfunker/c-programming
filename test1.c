#include <stdlib.h>
#include <string.h>
#include <stdio.h>
 
#define MAX_STRING_LENGTH   32
#define MAX_BOOKS       5
 
typedef struct {
    char name[MAX_STRING_LENGTH];
    char surname[MAX_STRING_LENGTH];
    char tel[MAX_STRING_LENGTH];
} book_t;
 
int sorter (const void * a, const void * b) {
    return strcmp (((book_t *)a)->name, ((book_t *)b)->name) > 0;
}
 
void book_print (book_t * b) {
    printf ("name   : %s\n"
             "surname: %s\n"
             "tel    : %s\n",
              b->name, b->surname, b->tel);
}
 
void book_printn (book_t * b, size_t num) {
    for ( ; num; --num) {
        book_print (b++);
        printf ("\n-----------------\n");
    }
}
 
int main()
{
    /*  поля заполнены от балды, потому что я не в курсе
     *  что именно они должны значить
     *  и вообще это больше похоже на структуру,
     *  описывающую `человека'
    */
    book_t books[MAX_BOOKS] = {
        { "The Jungle Book",    "Rudyard Kipling",  "1" },
        { "Frankenstein",   "Mary Wollstonecraft",  "2" },
        { "The Secret Garden",  "Frances Hodgson B",    "3" },
        { "Heidi",      "Johanna Spyri",    "4" },
        { "Enchiridion",    "Epictetus",        "5" }
    };
 
    printf ("---------------- BEFORE SORT ----------------\n");
    book_printn (books, MAX_BOOKS);
 
    // сортировка
    qsort (books, MAX_BOOKS, sizeof (book_t), sorter);
 
    printf ("---------------- AFTER SORT -----------------\n");
    book_printn (books, MAX_BOOKS);
 
    return 0;
}
