#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {                                                    // Abre o arquivo de entrada (txt) em modo leitura normal
  FILE *inputFile = fopen("input.asm", "r");
  if (inputFile == NULL) {
    printf("Erro ao abrir o arquivo de entrada.\n");
    return 1;
  }

                                                                
  FILE *outputFile = fopen("output.exe", "wb");                 // Abre o arquivo de saída (binário) em modo escrita
  if (outputFile == NULL) {
    printf("Erro ao abrir o arquivo de saída.\n");
    fclose(inputFile);
    return 1;
  }

  char bitString[9];      
  int leitura[8];                                               // Buffer para armazenar a linha lida
  while (fscanf(inputFile, "%d", leitura)) {
    leitura[strcspn(leitura, "\n")] = 0;                        // Remove qualquer caractere de nova linha (\n) ao final da string
    fwrite(&leitura, sizeof(leitura), 1, outputFile);
  }

  // Fechar arquivos
  fclose(inputFile);
  fclose(outputFile);

  printf("Conversão concluída com sucesso!\n");
  return 0;
}