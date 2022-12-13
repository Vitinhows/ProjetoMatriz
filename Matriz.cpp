#include "Matriz.h"
namespace ejm{//inicio
Matriz::Matriz(int qLinhas, int qColunas):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    pMatriz(0)
{
    if(qLinhas<=0) throw QString("Quantidade de Linhas somente positiva");
    if(qColunas<=0) throw QString("Quantidade de Colunas somente positiva");
    try{
        pMatriz = new int[qLinhas*qColunas];
    }catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    quantidadeDeLinhas = qLinhas;
    quantidadeDeColunas = qColunas;
}
Matriz::~Matriz(){if(pMatriz) delete[] pMatriz;}
int Matriz::getQuantidadeDeLinhas()const{
    return quantidadeDeLinhas;
}
int Matriz::getQuantidadeDeColunas()const{
    return quantidadeDeColunas;
}
void Matriz::setElemento(int elemento, int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    *(pMatriz+pos) = elemento;
}

int Matriz::getElemento(int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    return *(pMatriz+pos);
}

QString Matriz::getMatriz()const{
    QString saida = "";
    for(int linha = 0; linha < getQuantidadeDeLinhas(); linha++)
    {
        for(int coluna = 0; coluna < getQuantidadeDeColunas(); coluna++)
        {
            saida += QString::number(getElemento(linha,coluna));
            saida += "  ";
        }
        saida += "\n";
    }
    return saida;
}

Matriz* Matriz::adicionar (Matriz const * const mat)const{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser adicionadas matriz de tamanhos diferentes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) +
                        mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }
}

Matriz* Matriz::subtrair (Matriz const * const mat)const{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser subtraido matriz de tamanhos diferentes");
    try {
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) -
                        mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }

}

Matriz* Matriz::multiplicar (Matriz const * const mat)const{
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser multiplicado matriz de tamanhos diferentes");
    try {
        Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha=0; linha<quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) *
                        mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }

}

Matriz* Matriz::transposta()const{
    Matriz mat = mat.getMatriz();
    if( quantidadeDeLinhas  != mat->getQuantidadeDeLinhas() ||
        quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString("Nao pode ser multiplicado matriz de tamanhos diferentes");
    try {
         Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
         for(int linha=0; linha<quantidadeDeColunas; linha++)
                 {
                     for(int coluna=0; coluna<quantidadeDeLinhas; coluna++){
                         int valor = this->getElemento(linha,coluna);
                         aux->setElemento(valor,linha,coluna);
                     }
                 }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }
}




}//fim
