#include <stdio.h>

main()
{
	int x, y, z;

	x = ~0;
	x = 0x00000000;

	x = 0x80000000;
	x = 1 << 31;

	x = 0x7fffffff;
	x = ~(1 << 31);

	printf("%d\n", x);

	x = -57;

	x = 0x00000039;
	x = ~x;
	x = x + 1;
	printf("%x\n", x);

	x = -82;
	y = -36;
	z = x + y;
	printf("x = %x\ny = %x\nz = %x(%d)\n", x, y, z, z);
}