#include <cs50.h>
#include <stdio.h>
//funcao responsavel pelo espaco
void espaco(int m);
//funcao responsavel pelo #
void bloco(int n);


int main(void)
{
    int height;
    int andar = 1;
    //pergunta a altura da torre dentro do valor válido
    do
    {
        height = get_int("Heigth: ");
    }
    while (height < 1 || height > 8);
    int space = height - 1;
    //chama as funcoes para construir o próximo andar da torre e atualiza as variaveis
    do
    {
        espaco(space);
        bloco(andar);
        printf("  ");
        bloco(andar);
        printf("\n");
        andar++;
        space--;
        height--;
    }
    while (height > 0);
}

void bloco(int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("#");
    }
}

void espaco(int m)
{
    for (int i = 0; i < m; i++)
    {
        printf(" ");
    }
}

