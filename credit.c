#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void confere(long n);

int main(void)
{

    //Pega o numero do cartao de credito
    long cc = get_long("Credit Card Number: ");

    //Confere se e um numero de CC Valido
    confere(cc);

}

void confere(long n)
{
    //nDigits: tamanho do número em digitos
    long nDigits = floor(log10(labs(n))) + 1;
    //a: Oscilador que permitirá tratar digitos alternados de maneira diferente
    bool a = true;
    //vld: resultado que servirá para verificar a validade do cartão
    int vld = 0;
    //Armazena na váriável n2 que será manipulada
    long n2 = n;
    //A análise ocorrerá N vezes o número de dígitos
    for (int i = 0; i <= nDigits; i++)
    {
        //Utilizando o oscilador "a", trata cada dígito de maneira alternada
        if (a == true)
        {
            int digit = n2 % 10;
            vld = vld + digit;
            n2 /= 10;
            a = false;
        }
        else
        {
            int digit = (n2 % 10) * 2;
            //Se o dobro do dígito analisado conter 2 dígitos (10>=digit<=18), irá decompor o número em dígitos para que possam ser somados
            if (digit > 9)
            {
                while (digit > 0)
                {
                    int digit1 = digit % 10;
                    vld = vld + digit1;
                    digit /= 10;
                }
                n2 /= 10;
                a = true;
            }
            else
            {
                vld = vld + digit;
                n2 /= 10;
                a = true;;
            }

        }

    }
    //Confere se e um numero de CC Valido de acordo com as regras numéricas. Caso sim, confere se é de alguma bandeira
    if (vld % 10 == 0)
    {
        do
        {
            n = n / 10;
        }
        while (n >= 100);
        if (nDigits == 16 && (n >= 51 && n <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if (nDigits == 15 && (n == 34 || n == 37))
        {
            printf("AMEX\n");
        }
        else if ((nDigits == 16 || nDigits == 13) && n / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

