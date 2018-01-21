#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct {
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
	item i1,i2;
	i1.type = '0';
	i1.amount= '5';
	i1.unit = '0';
	
	i2.type = '1';
	i2.amount= '5';
	i2.unit = '1';

produce(&i1);
printf("Item 1: Type: %d, Amount: %d, Unit: %d \n", i1.type, i1.amount, i1.unit);
printf("Produce: First = %d, Last = %d \n", first, last);
produce(&i2);
printf("Item 2: Type: %d, Amount: %d, Unit: %d \n", i2.type, i2.amount, i2.unit);
printf("Produce: First = %d, Last = %d \n", first, last);

consume();
printf("Item consumed: First = %d, Last = %d \n", first, last);
return 0;
}


	





	
