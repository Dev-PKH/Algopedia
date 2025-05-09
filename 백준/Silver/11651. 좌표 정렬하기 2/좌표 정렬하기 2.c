#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x,y;
}point;

int cmp(point* a, point* b)
{
	if(a->y == b->y) return a->x - b->x;
	return a->y - b->y;
}

int main(void) {
	
	int count;
	point* p = NULL;
	
	scanf("%d", &count);
	
	p = (point*)malloc(sizeof(point) * count);
	
	for(int i=0; i<count; i++)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	
	qsort(p, count, sizeof(point), cmp);
	
	for(int i=0; i<count; i++)
	{
		printf("%d %d\n", p[i].x, p[i].y);
	}
	
	free(p);
	
	return 0;
}
