// Decode PTP packets from Canon software

#include <stdio.h>

#include "ptp.h"

void decodeBulkContainer(char file[]) {
	PTPUSBBulkContainer a;

	// Get 12 bytes before payload data
	FILE *f = fopen(file, "r");
	fread(&a, 1, 350, f);
	fclose(f);

	puts("Enable boot disk bulk container:");
	printf("Length: %u\n", a.length);
	printf("Type: %hu\n", a.type);
	printf("Code: %hu (0x%x)\n", a.code, a.code);
	printf("Transfer ID: %u\n", a.trans_id);
	printf("Payload Data: %s\n", a.payload.data);
	printf("Param: %d\n", a.payload.params.param1);
	printf("Param: %d\n", a.payload.params.param2);
	printf("Param: %d\n", a.payload.params.param3);
	printf("Param: %d\n", a.payload.params.param4);
	printf("Param: %d\n", a.payload.params.param5);
	putchar('\n');
}

int main() {
	decodeBulkContainer("enable");
}