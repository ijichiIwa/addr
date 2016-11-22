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
	int		n = 0;

	printf("char type 5\n\r");

	for(i=0;i<5;i++)
	{
		printf("%d\n\r", (n = (int)&a[i]));
	}

}

void outint()
{
	int		a[4];
	int		i = 0;
	int		n = 0;

	printf("int type 5\n\r");

	for(i=0;i<5;i++)
	{
		printf("%d\n\r", (n = (int)&a[i]));
	}

}

void outshort()
{
	short	a[4];
	int		i = 0;
	int		n = 0;

	printf("short type 5\n\r");

	for(i=0;i<5;i++)
	{
		printf("%d\n\r", (n = (int)&a[i]));
	}

}

void outlong()
{
	long	a[4];
	int		i = 0;
	int		n = 0;

	printf("long type 5\n\r");

	for(i=0;i<5;i++)
	{
		printf("%d\n\r", (n = (int)&a[i]));
	}

}

void outdouble()
{
	double	a[4];
	int		i = 0;
	int		n = 0;

	printf("double type 5\n\r");

	for(i=0;i<5;i++)
	{
		printf("%d\n\r", (n = (int)&a[i]));
	}

}

void outstruct()
{
	int		dat;
	struct	database data;


	printf("struct type\n\r");
	dat = (int)&data;
	printf("%d\n\r", dat);
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
