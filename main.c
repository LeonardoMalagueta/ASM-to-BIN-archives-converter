#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char Stringto8Byte(const char *bitString) {
    unsigned char byte = 0;
    int length = strlen(bitString);
    
    for (int i = 0; i < length; i++) {
        byte = byte << 1;  // Desloca os bits para a esquerda
        if (bitString[i] == '1') {
            byte |= 1;  // Coloca o bit 1 no bit menos significativo se for 1
        }
    }
    
    return byte;
}

int main() {
    // Abre o arquivo de entrada (txt) em modo leitura
    FILE *inputFile = fopen("input.asm", "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Abre o arquivo de saída (binário) em modo escrita
    FILE *outputFile = fopen("output.exe", "wb");
    if (outputFile == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(inputFile);
        return 1;
    }

    char bitString[100];  // Buffer para armazenar a linha
    int fflag = 0;

    while (fgets(bitString, sizeof(bitString), inputFile)) {
        bitString[strcspn(bitString, "\n")] = 0;  // Remove o '\n' no final da string
        
        if(!strcmp(bitString,"add")){
          unsigned char byte = Stringto8Byte("00000000");
          fwrite(&byte, sizeof(byte), 1, outputFile);
          fflag = 1;
        }else if(!strcmp(bitString,"sub")){
          unsigned char byte = Stringto8Byte("00000001");
          fwrite(&byte, sizeof(byte), 1, outputFile);
          fflag = 1;
        }else if(!strcmp(bitString,"and")){
          unsigned char byte = Stringto8Byte("00000010");
          fwrite(&byte, sizeof(byte), 1, outputFile);
          fflag = 1;
        }else if(!strcmp(bitString,"or")){
          unsigned char byte = Stringto8Byte("00000011");
          fwrite(&byte, sizeof(byte), 1, outputFile);
          fflag = 1;
        }else{
          if(fflag = 0){break;}
            unsigned char byte = Stringto8Byte(bitString);
            fwrite(&byte, sizeof(byte), 1, outputFile);
        }
    }

    // Fechar arquivos
    fclose(inputFile);
    fclose(outputFile);

    printf("Conversão concluída com sucesso!\n");
    return 0;
}