#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// invertir texto
void reverse(char* text, size_t len) {
    char* iptr = text;
    char* lptr = text+len-1;
    for (int i = 0; i < len/2; i++) {
        char temp = *iptr;
        *iptr = *lptr;
        *lptr = temp;
        lptr--;
        iptr++;
    }
}

// contar vocales y consonantes
void countVowelsConsonant(char* text, size_t len, unsigned int *vowels, unsigned int *consonants) {
    char* iptr = text;
    short unsigned spaces = 0;
    for (int i = 0; i < len; i++) {
        switch (*(iptr+i)) {
            case 'a': case 'A': (*(vowels+0))++; break;
            case 'e': case 'E': (*(vowels+1))++; break;
            case 'i': case 'I': (*(vowels+2))++; break;
            case 'o': case 'O': (*(vowels+3))++; break;
            case 'u': case 'U': (*(vowels+4))++; break;
            case ' ': spaces++; break;
        }
    }
    *consonants = len - spaces - (*(vowels+0)+ *(vowels+1)+ *(vowels+2)+ *(vowels+3)+ *(vowels+4));
}

// reemplazar espacios
void replaceSpaces(char* text, size_t len, char replacement) {
    char* iptr = text;
    for (int i = 0; i < len; i++) {
        if (*(iptr+i) == ' ') {
            *(iptr+i) = replacement;
        }
    }

}

int main(int argc, char *argv[]) {
    // chequear que el usuario introduzca un parametro al ejecutar el programa el cual es el texto
    if (argc != 2) {
        fprintf(stderr, "Insert a text of maximum 100 characters.\nExample: 'Hello world'\n");
        return 1;
    }

    // chequear que el texto ingresado sea de maximo 100 caracteres
    size_t len = strlen(argv[1]);
    if (len > 100) {
        fprintf(stderr, "Text exceeds 100 characters.\n");
        return 1;
    }

    // crear un espacio en memoria para el texto
    char* text = malloc(len+1);
    if (!text) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // asignacion de variables
    strcpy(text, argv[1]);
    unsigned int *vowels = malloc(sizeof(unsigned int) * 5);
    unsigned int consonants = 0;
    *vowels = 0;*(vowels+1) = 0;*(vowels+2) = 0;*(vowels+3) = 0;*(vowels+4) = 0;

    // llamado a funciones e impresion resultados

    // invertir texto
    printf("Original text: %s\n", text);
    reverse(text, len);
    printf("Reversesd text: %s\n", text);

    // contar vocales y consonantes
    countVowelsConsonant(text, len, vowels, &consonants);
    printf("Number of Vowels... Total=%d,"
           " a=%d,"
           " e=%d,"
           " i=%d,"
           " o=%d,"
           " u=%d\n",
           *(vowels+0)+ *(vowels+1)+ *(vowels+2)+ *(vowels+3)+ *(vowels+4),
           *(vowels+0), *(vowels+1), *(vowels+2), *(vowels+3), *(vowels+4));
    printf("Number of Consonants: %d\n", consonants);

    // reemplazar espacios por caracter '_'
    replaceSpaces(text, len, '_');
    printf("Replaced text: %s\n", text);

    // liberar memoria
    free(text);
    free(vowels);
    return 0;
}