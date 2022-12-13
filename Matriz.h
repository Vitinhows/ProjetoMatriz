#ifndef MATRIZ_H
#define MATRIZ_H
#include<QString>
namespace ejm{//inicio
class Matriz
{
private:
    int quantidadeDeLinhas;
    int quantidadeDeColunas;
    int *pMatriz;
public:
    Matriz(int qLinhas, int qColunas);
    ~Matriz();
    int getQuantidadeDeLinhas()const;
    int getQuantidadeDeColunas()const;
    void setElemento(int elemento, int linha, int coluna)const;
    int getElemento(int linha, int coluna)const;
    QString getMatriz()const;
    Matriz* adicionar(Matriz const * const mat)const;
    Matriz* subtrair(Matriz const * const mat)const;
    Matriz* multiplicar(Matriz const * const mat)const;
    Matriz* transposta()const;
    Matriz* potencia(int p)const;
};
}//fim
#endif // MATRIZ_H
