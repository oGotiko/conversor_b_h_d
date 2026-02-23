#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>

void pararTela() {
    system("pause");
}

void limparTela() {
    system("cls");
}

void menuInicial() {
    printf("\n>========| CONVERSOR DE NÚMEROS |=========<\n");
    printf("\n\n    Faça uma conversão de números entre (Binário, Decimal, Hexadecimal)      \n\n");
    printf("        1 - Conversões Binárias\n");
    printf("        2 - Conversões Decimais\n");
    printf("        3 - Conversões Hexadecimais\n");
    printf("        4 - Sair do Programa\n");
}

void menuBinario() {
    printf("\n\n>========| CONVERSÕES BINÁRIAS |=========<\n\n");
    printf("            1 - Binário -> Decimal\n");
    printf("            2 - Binário -> Hexadecimal\n");
    printf("            3 - Sair do Menu Atual\n");
}

void menuDecimal() {
    printf("\n\n>========| CONVERSÕES DECIMAIS |=========<\n\n");
    printf("            1 - Decimal -> Binário\n");
    printf("            2 - Decimal -> Hexadecimal\n");
    printf("            3 - Sair do Menu Atual\n");
}

void menuHexadecimal() {
    printf("\n\n>========| CONVERSÕES HEXADECIMAIS |=========<\n\n");
    printf("            1 - Hexadecimal -> Binário\n");
    printf("            2 - Hexadecimal -> Decimal\n");
    printf("            3 - Sair do Menu Atual\n");
}

void digiteOpcao() {
    printf("\nDigite uma opção: ");
}

int binarioParaDecimal(char caracteres[200]) {
    int resultado = 0;
    for (int i = 0; caracteres[i] != '\0'; i++) {
        if (caracteres[i] != '0' && caracteres[i] != '1') return -1;
        resultado = resultado * 2 + (caracteres[i] - '0');
    }
    return resultado;
}

void decimalParaBinario(int decimal, char binario[200]) {
    if (decimal == 0) {
        strcpy(binario, "0");
        return;
    }
    char temp[200];
    int i = 0;
    while (decimal > 0) {
        temp[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    for (int j = 0; j < i; j++) {
        binario[j] = temp[i - j - 1];
    }
    binario[i] = '\0';
}

void hexadecimalParaBinario(char hex[200], char binario[200]) {
    binario[0] = '\0';
    for (int i = 0; hex[i] != '\0'; i++) {
        char c = hex[i];
        int valor;
        if (c >= '0' && c <= '9') valor = c - '0';
        else if (c >= 'A' && c <= 'F') valor = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f') valor = c - 'a' + 10;
        else {
            strcpy(binario, "ERRO");
            return;
        }
        for (int j = 3; j >= 0; j--) {
            char bit = ((valor >> j) & 1) + '0';
            strncat(binario, &bit, 1);
        }
    }
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    int opcaoTipo;

    do {
        limparTela();
        menuInicial();
        digiteOpcao();
        scanf("%d", &opcaoTipo);

        switch (opcaoTipo) {
            case 1: { 
                int opcao;
                do {
                    limparTela();
                    menuBinario();
                    digiteOpcao();
                    scanf("%d", &opcao);

                    switch (opcao) {
                        case 1: {
                            char entrada[200];
                            printf("Digite um binário: ");
                            scanf("%s", entrada);
                            int decimal = binarioParaDecimal(entrada);
                            if (decimal == -1) printf("[ERRO] Não é binário!\n");
                            else printf("\nResultado: %d\n", decimal);
                            pararTela();
                            break;
                        }
                        case 2: {
                            char entrada[200], hex[50];
                            printf("Digite um binário: ");
                            scanf("%s", entrada);
                            int decimal = binarioParaDecimal(entrada);
                            if (decimal == -1) printf("[ERRO] Não é binário!\n");
                            else {
                                sprintf(hex, "%X", decimal);
                                printf("\nResultado: %s\n", hex);
                            }
                            pararTela();
                            break;
                        }
                        case 3: break;
                        default: printf("Opção inválida!\n");
                    }
                } while (opcao != 3);
                break;
            }
            case 2: { 
                int opcao;
                do {
                    limparTela();
                    menuDecimal();
                    digiteOpcao();
                    scanf("%d", &opcao);

                    switch (opcao) {
                        case 1: {
                            int numero;
                            char binario[200];
                            printf("Digite um decimal: ");
                            scanf("%d", &numero);
                            decimalParaBinario(numero, binario);
                            printf("\nResultado: %s\n", binario);
                            pararTela();
                            break;
                        }
                        case 2: {
                            int numero;
                            char hex[50];
                            printf("Digite um decimal: ");
                            scanf("%d", &numero);
                            sprintf(hex, "%X", numero);
                            printf("\nResultado: %s\n", hex);
                            pararTela();
                            break;
                        }
                        case 3: break;
                        default: printf("Opção inválida!\n");
                    }
                } while (opcao != 3);
                break;
            }
            case 3: { 
                int opcao;
                do {
                    limparTela();
                    menuHexadecimal();
                    digiteOpcao();
                    scanf("%d", &opcao);

                    switch (opcao) {
                        case 1: {
                            char entrada[200], binario[1024];
                            printf("Digite um hexadecimal: ");
                            scanf("%s", entrada);
                            hexadecimalParaBinario(entrada, binario);
                            if (strcmp(binario, "ERRO") == 0) printf("[ERRO] Não é hexadecimal!\n");
                            else printf("\nResultado: %s\n", binario);
                            pararTela();
                            break;
                        }
                        case 2: {
                            char hex[200];
                            int decimal;
                            printf("Digite um hexadecimal: ");
                            scanf("%s", hex);
                            sscanf(hex, "%X", &decimal);
                            printf("\nResultado: %d\n", decimal);
                            pararTela();
                            break;
                        }
                        case 3: break;
                        default: printf("Opção inválida!\n");
                    }
                } while (opcao != 3);
                break;
            }
            case 4: break;  
            default: printf("Opção inválida!\n");
        }

    } while (opcaoTipo != 4);

    return 0;
}