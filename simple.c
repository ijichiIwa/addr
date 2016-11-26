#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int ErrorCheck(int eNumL)
{
	// проверяем что число меньше 2.
	if(eNumL<2)
		{
			printf("Error!");
			getch();
			return 0;
		}
	return 1;
}

short EnterNum()
{
		int		eNumL = 0;
		printf("enter 2+, not float:");
		scanf("%d", &eNumL);

		return eNumL;
}

void OutputNum(int *massNumL, int *i)
{
	short		j = 0;
	for(j=0;j<*i;j++)
	{
		printf("_%d", massNumL[j]);
	}
}

void CheckNum(int eNumL)
{
	// Проверяем числа на простоту.
	short		i = 0;
	short		j = 0;
	short		k = 0;
	short		flag = 0;
	int			n = 0;

	printf("2"); //первое простое число, не вычисляемое.

	int *massNumL = NULL;
	massNumL = (int*)malloc(sizeof(int)*(eNumL));

	for(i = 0; i < eNumL; i++)
	{
	     massNumL[i] = 0;
	}
	for(j = 2; j <= eNumL; j++)
		{
		for(k = 2; k < j; k++)
						{
						if (j%k == 0)
							{
							flag = 0;
							break;
							}
						else
							{
							flag = 1;
							}
						}
		if(flag==1)
			{
			massNumL[n] = j;
			n++;
			}
		}
	OutputNum(massNumL, &n); //вывод результатов.
}



int main(void) {

	short		eNum = 0;

	eNum = EnterNum(); //записываем полученное число.
	if(!ErrorCheck(eNum)) return 0; //проверяем полученное число.
	CheckNum(eNum); //передаем полученое число на вычисления и вывод.

	getch();
	return 0;
}
