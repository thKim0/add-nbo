#include<stdio.h>
#include<stdint.h>
#include<netinet/in.h>

int main(int argc, char* argv[]){

	if(argc < 3){
		printf("Usage : %s <file1> <file2>\n", argv[0]);
		return 0;
	}
	
	FILE *fp1;
	FILE *fp2;
	uint32_t num1, num2;
	uint32_t tmp;

	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");

	fread(&num1, sizeof(uint32_t), 1, fp1);
	fread(&num2, sizeof(uint32_t), 1, fp2);

	num1 = htonl(num1);
	num2 = htonl(num2);

	tmp = num1 + num2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, tmp, tmp);

	fclose(fp2);
	fclose(fp1);

}
