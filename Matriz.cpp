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


    try {
         Matriz *aux = new Matriz(quantidadeDeColunas,quantidadeDeLinhas);
         for(int linha=0; linha<quantidadeDeLinhas; linha++)
                 {
                     for(int coluna=0; coluna<quantidadeDeColunas; coluna++){
                         int valor = this->getElemento(linha,coluna);
                         aux->setElemento(valor,coluna, linha);
                     }
                 }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }

}

Matriz* Matriz::potencia(int p)const{
    try {
        Matriz *aux = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);
        for(int linha=0; linha<this->quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<this->quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        }
        int cont = 1;
           if(p>1){

               while(cont < p){

                   aux = aux->multiplicar(this);
                   cont++;
               }
           }

        return aux;

    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }


}

Matriz* Matriz::vezesK(int p)const{
    try {
        Matriz *aux = new Matriz(this->quantidadeDeLinhas,this->quantidadeDeColunas);
        for(int linha=0; linha<this->quantidadeDeLinhas; linha++){
            for(int coluna=0; coluna<this->quantidadeDeColunas; coluna++){
                int valor = this->getElemento(linha,coluna) * p;
                aux->setElemento(valor,linha,coluna);

            }
        }
        return aux;

}

    catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
}

bool Matriz::eIgual(const Matriz * const mat){
    int j,i;
    for(int linha=0; linha<this->quantidadeDeLinhas; linha++){
        for(int coluna=0; coluna<this->quantidadeDeColunas; coluna++){
            for(i = 0; i < mat->quantidadeDeLinhas and *(this->pMatriz + linha) != *(mat->pMatriz + i); i++);
            for(j = 0; j < mat->quantidadeDeColunas and *(this->pMatriz + coluna) != *(mat->pMatriz + j); j++);
            if(j == mat->quantidadeDeLinhas and j == mat->quantidadeDeColunas
                    and i == mat->quantidadeDeLinhas and i== mat->quantidadeDeColunas) return false;
        }

    }
    return true;
}

bool Matriz::triangularSup()const{
        int linha;
        for(int coluna=0; coluna<this->quantidadeDeColunas; coluna++){
            for(linha=coluna + 1; linha<this->quantidadeDeLinhas and this->getElemento(linha,coluna) == 0; linha++);
                if(linha < quantidadeDeLinhas){
                    return false;
                }
        }
    return true;
}

bool Matriz::simetrica()const{
    if(quantidadeDeLinhas != quantidadeDeColunas) throw QString("Matriz não quadrada");
    Matriz *aux = this->transposta();
    int cont = 0;
    for(int linha = 0; linha<quantidadeDeLinhas; linha++){
        for(int coluna = 0; coluna<quantidadeDeColunas; coluna++){
            int valorMatA = this->getElemento(linha,coluna);
            int valorMatAux = aux->getElemento(linha,coluna);
            if(valorMatAux == valorMatA) cont++;
        }

    }
    if(cont==(quantidadeDeLinhas*quantidadeDeColunas)) return true;
    return false;
}



}//fim
