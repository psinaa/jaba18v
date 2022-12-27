#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
struct point {
	float x;
	float y;
	char name;
};
typedef struct point Point;
void Put(Point a) {
	printf("point %c (%.1f, %.1f)\n", a.name, a.x, a.y);
}
Point vvedite_tochku()
{
	Point a;
	short q;
	int xa, xy;
	printf("Введи название точки\n");
	scanf("%s", &q);
	printf("x:");
	scanf("%d", &xa);
	printf("y:");
	scanf("%d", &xy);
	a.name = q; a.x = xa; a.y = xy;
	return a;
}
void rasst(Point a, Point b)
{
	double rast;
	rast = sqrt(pow(fabs(a.x - b.x), 2) + pow(fabs(a.y - b.y), 2));
	return printf("%lf\n", rast);
}
void seredina(Point a, Point b)
{
	Point m;
	m.name = 'M'; m.x = (a.x + b.x) / 2; m.y = (a.y + b.y) / 2;
	return printf("point %c (%.1f, %.1f)\n", m.name, m.x, m.y);
}
void chetvert(Point a)
{
	if (a.x > 0)
	{
		if (a.y > 0) printf("1 четверть\n");
		else printf("4 четверть\n");
	}
	if (a.x < 0)
	{
		if (a.y > 0) printf("2 четверть\n");
		else printf("3 четверть\n");
	}
}
int main()
{
	Point r, y;
	setlocale(LC_ALL, "rus");
	int sch = 0;
	r.name = 'R'; r.x = 0; r.y = 0;
	y.name = 'Y'; y.x = 0; y.y = 0;
	while (sch != 6)
	{
		puts("Меню:\n1 - ввести значения\n2 - вывод точек\n3 - расстояние между точками\n4 - середина между точками\n5 - четверть\n6 - выход");
		scanf("%d", &sch);
		switch (sch)
		{
		case 1:
			r = vvedite_tochku();
			y = vvedite_tochku();
			break;
		case 2:
			Put(r);
			Put(y);
			break;
		case 3:
			rasst(r, y);
			break;
		case 4:
			seredina(r, y);
			break;
		case 5:
			chetvert(r);
			break;
		}
	}
}