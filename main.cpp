
#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h>
#include <arpa/inet.h>
void dump(void* p, size_t n) {
	uint8_t* u8 = static_cast<uint8_t*>(p);
	size_t i = 0;
	while (true) {
		printf("%02X ", *u8++);
		if (++i >= n) break;
		if (i % 8 == 0)
			printf("\n");
	}
	printf("\n");
}
uint16_t my_ntohs(uint16_t a){
	uint16_t a1 =(a & 0xFF00)>>8;
	uint16_t a2 =(a & 0x00FF)<<8;
	return ( a1 | a2);
}
void write_4660() {
	uint16_t port = 4660; // 0x1234
	printf("port number = %d\n", port);
	dump(&port, sizeof(port));
}

void  write_0x1234() {
	uint8_t network_buffer[] = { 0x12, 0x34 };
	uint16_t* p = reinterpret_cast<uint16_t*>(network_buffer);
	uint16_t n = my_ntohs(*p); // TODO
	printf("16 bit number=0x%x\n", n);
}

uint32_t my_ntol(uint32_t a){

	uint32_t b1 = (a & 0xFF000000)>>24;
	uint32_t b2 = (a & 0x00FF0000)>>8;
	uint32_t b3 = (a & 0x0000FF00)<<8;
	uint32_t b4 = (a & 0x000000FF)<<24;

	return (b1|b2|b3|b4);
}

void  write_0x12345678() {
	uint8_t network_buffer[] = { 0x12, 0x34, 0x56, 0x78 };
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	uint32_t n =my_ntol( *p); // TODO
	printf("32 bit number=0x%x\n", n);
}
void homework(){
        uint32_t buffer[127]={0,};
	uint32_t buffer2[127]={0,};
	FILE *fp2;
        FILE *fp;
        fp = fopen("thousand.bin","rb");
	fp2 = fopen("five-hundred.bin","rb");
        uint32_t ret,ret2,ret3,ret4;

        ret = fread(buffer, sizeof("thousand.bin"), 127,fp);
	ret3 = fread(buffer2, sizeof("five-hundred.bin"),127,fp2);

	ret2 =ntohl( *buffer);
	ret4 =ntohl( *buffer2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",ret2,ret2,ret4,ret4,ret2+ret4,ret2+ret4);

        fclose(fp);
}

int main() {
//	write_4660();
//	write_0x1234();
//	write_0x12345678();
	homework();
//	return 0;
}
