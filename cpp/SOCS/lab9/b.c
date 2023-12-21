#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 100000

char globalArr[TABLE_SIZE][100];

unsigned long hash(unsigned char *str)
{
    const unsigned int fnv_prime = 0x811C9DC5;
	unsigned int hash = 0;
	unsigned int i = 0;
    unsigned int length = strlen(str);

	for (i = 0; i < length; str++, i++)
	{
		hash *= fnv_prime;
		hash ^= (*str);
	}

	return hash % TABLE_SIZE;
}


void setHash(unsigned char *key, unsigned char *value) {
    unsigned int hashedKey = hash(key);

    printf("%u : %s : %s\n", hashedKey, key, value);

    strcpy(globalArr[hashedKey], value);
}

int main() {
    int dictWords;
    scanf("%d", &dictWords);
    getchar();
    for (int i = 0;i < dictWords;i++) {
        char strKey[50];
        char strValue[50];
        scanf("%[^#]#%s", strKey, strValue);
        getchar();
        setHash(strKey, strValue);
    }
    int testCase;
    scanf("%d", &testCase);
    getchar();
    char sentences[testCase][1000];
    for (int i = 0;i < testCase;i++) {
        scanf("%[^\n]", sentences[i]);
        getchar();
    }
    for (int i = 0;i < testCase;i++) {
        printf("Case %d: ", i+1);
        char *token = strtok(sentences[i], " ");
        while (token != NULL) {
            unsigned int hashed = hash(token);
            //printf("%s ", globalArr[hash(token)]);
            //printf("%u ", hash(token));
            if (strlen(globalArr[hashed]) == 0) {
                printf("%s ", token);
            } else {
                printf("%s ",globalArr[hashed]);
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }
}

