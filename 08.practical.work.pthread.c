#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 10

typedef struct {
	char type;
	int amount;
	int unit;
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
	while ((first +1) % BUFFER_SIZE == last) {

	}
	memcpy(&buffer[first], i , sizeof(item));
	first = (first +1) % BUFFER_SIZE;
}

item *consume()	{
	item *i = malloc(sizeof(item));
	while (first == last) {

	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last +1) % BUFFER_SIZE;
	return i;
}

void display(item i) {
	printf("Type: %d , Amount: %d , Unit: %d\n",i.type,i.amount,i.unit);
}

void *threadFunction1(void *param) {
	item i1,i2,i3;
	i1.type = '1';
	i1.amount = '3';
	i1.unit = '0';

	i2.type = '0';
	i2.amount = '4';
	i2.unit = '1';
	
	i3.type = '1';
	i3.amount = '8';
	i3.unit = '1';

	produce(&i1);
	printf( "Item 1: Type: %d , Amount: %d , Unit: %d \n Fist = %d , Last = %d \n", i1.type, 	i1.amount, i1.unit, first, last);

	produce(&i2);
	printf( "Item 2: Type: %d , Amount: %d , Unit: %d \n Fist = %d , Last = %d \n", i2.type, 	i2.amount, i2.unit, first, last);

	produce(&i3);
	printf( "Item 3: Type: %d , Amount: %d , Unit: %d \n Fist = %d , Last = %d \n", i3.type, i3.amount, i3.unit, first, last);
}

void *threadFunction2(void *param) {
	consume();
	display(*consume());
	display(*consume());
}


int main() {
	pthread_t tid1;
	pthread_create(&tid1,NULL,threadFunction1,NULL);
	pthread_join(tid1,NULL);
	pthread_t tid2;
	pthread_create(&tid2,NULL,threadFunction2,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
	
