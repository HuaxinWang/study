#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	int id;
	char name[20];
	int score;
};

int num_g = 1000;

void test();

int main(int argc, char *argv[])
{
	int num_l = 33;
	struct student *p = NULL;

	p = (struct student *)malloc(sizeof(struct student));

	p->id = 7;
	strcpy(p->name, "tom");
	p->score = 100;

	printf("&num_g : %p\n", &num_g);
	printf("&num_l : %p\n", &num_l);
	printf("p : %p\n", p);
	printf("test : %p\n", test);

	test();

	free(p);

	return 0;
}

void test()
{
	int test_l = 19;
	static test_sl = 18;

	printf("&test_l : %p\n", &test_l);
	printf("&test_sl : %p\n", &test_sl);
}
