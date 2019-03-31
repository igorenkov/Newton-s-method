#include <stdio.h>
#include <math.h>
//Функция
float Func(float x) {
	float fx = x * x * x + 4 * x - 3;
	return fx;
}
//Производная функции
float dFunc(float x) {
	float  fx = 3 * x * x + 4;
	return fx;
}
//Функция нахождения корня
float solve(float x0, float accuracy) {
	float x1 = x0;
	x0 = x0 - Func(x0) / dFunc(x0);	//Первый шаг
	float degree = pow(10, -accuracy);

	while (fabs(x1 - x0) > degree) {
		x1 = x0;
		x0 = x0 - Func(x0) / dFunc(x0);
	}
	return x0;
}

int main() {
	char ch;
	do {
		float x, x0, accuracy;

		printf("Input X0: ");
		scanf_s("%f", &x0);
		printf("Input accuracy: ");
		scanf_s("%f", &accuracy);
		//Нахождение корня
		x = solve(x0, accuracy);
		printf("%.10f", x);

		//Повтор программы
		printf("\nDo you wish to restart program? (y/n)\n");
		getchar();
		scanf_s("%c", &ch);
	} while (ch == 'y' || ch == 'Y');
	return 0;
}