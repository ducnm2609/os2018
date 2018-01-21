#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct (
	char type; 	// 0=fried chicken, 1=french friez
	int amount;	// pieces of weight
	char unit;	// 0=pieces, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
    while ((first + 1) % BUFFER_SIZE == last) {

    }
    memcpy(&buffer[first], i, sizeof(item));
    first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
    item *i = malloc(sizeof(item));
    while (first == last) {

    }
    memcpy(i, &buffer[last], sizeof(item));
    last = (last + 1) % BUFFER_SIZE;
    return i;
}

int main() {
	item a,b;
	a.type = '0';
	a.amount= '5';
	a.unit = '0';
	
	b.type = '1';
	b.amount= '10';
	b.unit = '1';

produce(&a);
printf("Item a: Type: %d, Amount: %d, Unit: %d \n", a.type, a.amount, a.unit);
printf("Produce: First = %d, Last = %d \n", first, last);
produce(&b);
printf("Item b: Type: %d, Amount: %d, Unit: %d \n", b.type, b.amount, b.unit);
printf("Produce: First = %d, Last = %d \n", first, last);

consume();
printf("Item consumed: First = %d, Last = %d \n", first, last);
return 0;
}


	





	
