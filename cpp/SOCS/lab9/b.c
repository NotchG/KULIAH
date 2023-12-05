#include <stdio.h>
#define TABLE_SIZE 100

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}

void setHash(unsigned char *key, unsigned char *value) {
    
}

int main() {

}

