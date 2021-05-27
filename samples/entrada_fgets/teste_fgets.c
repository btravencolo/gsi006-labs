#include <stdio.h>
#include <string.h>

int main()
{
    char str[6];
    printf("Digite (oi):\n");
    fgets(str,6,stdin);
    printf("Texto digitado: >>%s<<\n", str);
    
    printf("Digite (oi):\n");
    fgets(str,6,stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Texto digitado substituindo o \\n: >>%s<<\n", str);

    printf("Digite (oioioi):\n");
    fgets(str,6,stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Texto digitado: >>%s<<\n", str);
    fgets(str,6,stdin);
    printf("Texto que sobrou no buffer: %s\n", str);

    printf("Digite (oioioioioi):\n");
    fgets(str,6,stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Texto digitado: >>%s<<\n", str);
    fgets(str,6,stdin);
    printf("Texto que sobrou no buffer: %s\n", str);


    return 0;
}