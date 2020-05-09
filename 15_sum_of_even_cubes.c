#include <stdio.h>
#include <math.h>

int main()
{
	long long n, i, x, s;
	s=0;
	(void) scanf("%lld\n", &n);
	for(i=1; i<=n; i++)
		{
		
		(void) scanf ("\n");
		(void) scanf ("%lld", &x);
		s=s+(((i+1) % 2)*(x*x*x));
		}
	printf("%lld\n", (s));
	return 0;
}
