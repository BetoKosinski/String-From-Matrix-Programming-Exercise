#define _CRT_SECURE_NO_WARNINGS //para evitar warnings, não recomendado mas a questão garante que o buffer é suficiente
#include "BuildStringFromMatrix.h" //referência do header
#include <cstdio>  // Necessário para sprintf

void BuildStringFromMatrix(int* Matrix, int NumRows, int NumColumns, char* OutBuffer)
{    
    int charIndex = 0;

    //fórmula pra saber a posição de um elemento da matriz: k = i * N +j

    //top — linha mínima percorre até top++
    //bottom — linha máxima percorre até bottom--
    //left — coluna mínima percorre até left++
    //right — coluna máxima percorre até right--
    int top = 0;
    int bottom = NumRows - 1;
    int left = 0;
    int right = NumColumns - 1;

    //como funciona a ordem dos elementos:
    //de (0, 0) até (0, NumColumns - 1) 
    //de (0, NumColumns - 1) até (NumRows - 1, NumColumns - 1) 
    //de (NumRows - 1, NumColumns - 1) até (NumRows - 1, 0) 
    //de (NumRows - 1, 0) até (1, 0)
    //de (1, 0) até (1, NumColumns - 2) 
    //de (1, NumColumns - 2) até (NumRows - 2, NumColumns - 2)      

    //a primeira volta vai até os valores máximo de Row e Col,
    //quando tende a ir pro valor minimo acrescenta 1 e quanto tende a ir pro valor máximo diminui 1 por volta

    //Enunciado: Outbuffer já é grande o suficiciente, não precisa verificar o espaço, pode usar o sprintf ao invés de snprintf
    //função sprintf(buffer, "%d, ", Value);             

    while (top <= bottom && left <= right) //executa enquanto ainda tiver linhas e colunas não percorridas 
    {
        //indo para direita: row fixo = top, col varia    
        for (int col = left; col <= right; col++)
        {
            int value = Matrix[top * NumColumns + col]; //percorre a linha top da esquerda para direita   
            int written = sprintf(&OutBuffer[charIndex], "%d, ", value);
            charIndex += written; // avança o índice pelo que foi escrito
        }
        top++; 

        //indo para baixo: col fixo = right, row varia
        for (int row = top; row <= bottom; row++)
        {
            int value = Matrix[row * NumColumns + right]; //percorre a coluna right de cima para baixo
            int written = sprintf(&OutBuffer[charIndex], "%d, ", value);
            charIndex += written; // avança o índice pelo que foi escrito
        }
        right--; 

        //após o debug, verifiquei que os movimentos de esquerda e cima ainda estavam sendo feitos depois de percorrer a matriz por completo
        //colocar um if pra verificar se ainda existem linhas e colunas válidas    

        if (top <= bottom)
        {
            //indo para esquerda: row fixo bottom, col varia
            for (int col = right; col >= left; col--)
            {
                int value = Matrix[bottom * NumColumns + col]; //percorre a linha bottom da direita para esquerda
                int written = sprintf(&OutBuffer[charIndex], "%d, ", value);
                charIndex += written; // avança o índice pelo que foi escrito
            }
            bottom--;

        }

        if (left <= right)
        {

            //indo para cima: col fixo = left, row varia
            for (int row = bottom; row >= top; row--)
            {
                int value = Matrix[row * NumColumns + left]; //percorre a coluna left de baixo para cima
                int written = sprintf(&OutBuffer[charIndex], "%d, ", value);
                charIndex += written; // avança o índice pelo que foi escrito
            }
            left++;

        }
    }

    //dessa forma o último elemento vai terminar com o separador "%d, "
    //para evitar isso, volta duas posições no índice e coloca '\0'

    OutBuffer[charIndex - 2] = '\0'; //apaga o ", " final
}