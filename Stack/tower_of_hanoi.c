#include <stdio.h>
#include <stdlib.h>
#include "TowerOfHanoi.c"

int main()
{   int n;
    printf("no of disks: ");
    scanf("%d", &n);

	towerOfHanoi(n);
    return 0;
}
