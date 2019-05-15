#include<stdio.h>
#include<string.h>

struct Book{
  int id,price;
  char name[100];
 } book;

void bookprint(struct Book);
struct Book bookCreate(int i, char * str, int price);

int main()
{
  printf("Struct Example\n");
  struct Book b1 = bookCreate(1, "nome1", 10.0);;
  bookPrint(b1);
  return 0;
}

struct Book bookCreate(int id, char * str, int price)
{  
  struct Book b1;  
  printf("\nCreatingg book\n");
  b1.id = id;
  strcpy (b1.name, str);
  b1.price = price;
  return b1;
}

void bookPrint(struct Book b1)
{    
   printf("Book id=%d\n", b1.id);
   printf("Book Name=%s\n",b1.name);
   printf("Book Price=%d\n",b1.price);
}