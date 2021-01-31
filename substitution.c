#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int conta;
int value;


int main(int argc, string argv[])
{
    //Checa se o número de argumentos é correto
    if (argc != 2)
    {
        printf("Número de argumentos errado\n");
        return 1;
    }
    string key = argv[1];
    int len = strlen(key);
    //Checa se o tamanho da chave é correto
    if (len == 26)
    {
        //Checa se há caracteres não alfabéticos
        for (int i = 0; i < len; i++)
        {
            if (isalpha(key[i]) == 0)
            {
                printf("Caracteres não alfabéticos na chave\n");
                return 1;
            }

        }
        //Checa se há letras repetidas
        for (int j = 0; j < len; j++)
        {
            conta = 0;
            for (int k = 0; k < len; k++)
            {
                if (key[j] == key[k])
                {
                    conta++;
                }
                if (conta > 1)
                {
                    printf("Input errado, Letras repetidas\n");
                    return 1;
                }
            }
        }
        //Pega o texto a ser encriptado
        string plaintext = get_string("plaintext: ");
        int lenplain = strlen(plaintext);
        //Cria uma string que armazenará a mensagem encripitada
        char ciphertext[lenplain];
        //Adiciona o ponto de parada do array que armazenará a mensagem encripitada
        ciphertext[lenplain] = '\0';
        //Encripta a mensagem
        for (int l = 0; l < lenplain; l++)
        {
            if (isalpha(plaintext[l]) == 0)
            {
                ciphertext[l] = plaintext[l];
            }
            else
            {
                if (islower(plaintext[l]))
                {
                    value = plaintext[l] - 97;
                    ciphertext[l] = tolower(key[value]);
                }
                else if (isupper(plaintext[l]))
                {
                    value = plaintext[l] - 65;
                    ciphertext[l] = toupper(key[value]);
                }
            }
        }
        printf("ciphertext: %s\n", ciphertext);
    }
    else
    {
        printf("Número de caracteres da chave errados\n");
        return 1;
    }

}
