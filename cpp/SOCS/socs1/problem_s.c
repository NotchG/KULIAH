#include <stdio.h>


int main()
{
    char text[101];
    scanf("%[^\n]", &text);
    printf("#include <stdio.h>\n"
    "int main()\n"
    "{\n"
    "    printf(\"%%s\\n\",\"%s\");\n"
    "    return 0;\n"
    "}\n", text);
    return 0;
}