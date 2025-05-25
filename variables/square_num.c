#include <stdio.h>
int main()
{
	int enter_num, square_num;
	printf("Enter an integer: ");
	scanf("%d", &enter_num);

	square_num = enter_num * enter_num;
	printf("The square of the number you entered is %d", square_num);
	return 0;

}