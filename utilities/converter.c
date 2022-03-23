#include <stdio.h>

int converter(char* string) { 
    unsigned int buf = 0;
    while (*(string++)) {
        buf += (*string | 0x20);
        buf = (buf << 24 | buf >> 8 ); /* rotl */
    }
    return buf;
}

int main(int argc, char* argv[]) { 
	if(argc != 2) {
		return -1;
	}
	char *payload = argv[1];
	unsigned int hashed = converter(payload);
	printf("0x%x\n",hashed);

	return hashed;
}
