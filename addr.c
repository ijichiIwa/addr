#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct database
{
	int rowID;
	int name;
	float surname;
};

void outchar()
{
	char	a[4];
	int		i = 0;

	printf("char type 5\n\r");

	for(i=0;i<5;i++)
	{
		printf("%d\n\r", (int)&a[i]);
	}

}

void outint()
{
	int		a[4];
	int		i = 0;

	printf("int type 5\n\r");

	for(i=0;i<5;i++)
	{
		printf("%d\n\r", (int)&a[i]);
	}

}

void outshort()
{
	short	a[4];
	int		i = 0;

	printf("short type 5\n\r");

	for(i=0;i<5;i++)
	{
		printf("%d\n\r", (int)&a[i]);
	}

}

void outlong()
{
	long	a[4];
	int		i = 0;

	printf("long type 5\n\r");

	for(i=0;i<5;i++)
	{
		printf("%d\n\r", (int)&a[i]);
	}

}

void outdouble()
{
	double	a[4];
	int		i = 0;

	printf("double type 5\n\r");

	for(i=0;i<5;i++)
	{
		printf("%d\n\r", (int)&a[i]);
	}

}

void outstruct()
{
	struct	database data[4];
	int		i = 0;
	int		value = 0;
	int		j = 0;

	printf("struct type 5\n\r");

	for(i=0;i<5;i++)
	{
		j++;
		printf("%d\n", (int)&data[i]);

		value = (int)&data[j] - (int)&data[j-1];
		printf("val:%d\n\r", value);
	}
}

int main(void) {

	outchar();
	outint();
	outshort();
	outlong();
	outdouble();
	outstruct();


	getch();
	return EXIT_SUCCESS;
}
