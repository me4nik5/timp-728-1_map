#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, x;
	float s;
	s=0;
	(void) scanf("%d\n", &n);
	for(i=1; i<=n; i++)
		{
		(void) scanf("%d", &x);
		printf(" ");
		s=s+x;
		}
	printf("%lf\n", (s/n));
	return 0;
}
