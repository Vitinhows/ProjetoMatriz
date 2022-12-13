#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    matA(0),
    matB(0)
{
    ui->setupUi(this);
    ui->textEditSaidaMatA->setEnabled(false);
    ui->pushButtonApagarMatA->setEnabled(false);
    ui->textEditSaidaMatB->setEnabled(false);
    ui->pushButtonApagarMatB->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if(matA) delete matA;
    if(matB) delete matB;
    delete ui;
}

void MainWindow::on_pushButtonCriarMatA_clicked()
{
    try {
        int linha = ui->lineEditQuantidadeLinhasMatA->text().toInt();
        int coluna = ui->lineEditQuantidadeColunasMatA->text().toInt();
        matA = new ejm::Matriz(linha,coluna);
        for(int l=0; l < linha ; l++){
            for(int c=0; c < coluna; c++){
                int elemento =  QInputDialog::getInt(this , "Leitura",
                                "Matriz A [ "+ QString::number(l) + ", "+
                                QString::number(c) + "] = ");
                matA->setElemento(elemento,l,c);
            }
        }
        ui->textEditSaidaMatA->setText(matA->getMatriz());
        ui->lineEditQuantidadeColunasMatA->setEnabled(false);
        ui->lineEditQuantidadeLinhasMatA->setEnabled(false);
        ui->pushButtonCriarMatA->setEnabled(false);
        ui->pushButtonApagarMatA->setEnabled(true);
    }
    catch(std::bad_alloc&){
        QMessageBox::information(this,"ERRO NO SISTEMA","Matriz nao pode ser criada");
    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }
}

void MainWindow::on_pushButtonApagarMatA_clicked()
{
    if(matA) delete matA;
    matA = 0;
    ui->lineEditQuantidadeColunasMatA->clear();
    ui->lineEditQuantidadeLinhasMatA->clear();
    ui->textEditSaidaMatA->clear();
    ui->lineEditQuantidadeColunasMatA->setEnabled(true);
    ui->lineEditQuantidadeLinhasMatA->setEnabled(true);
    ui->pushButtonCriarMatA->setEnabled(true);
    ui->pushButtonApagarMatA->setEnabled(false);
}

void MainWindow::on_pushButtonCriarMatB_clicked()
{
    try {
        int linha = ui->lineEditQuantidadeLinhasMatB->text().toInt();
        int coluna = ui->lineEditQuantidadeColunasMatB->text().toInt();
        matB = new ejm::Matriz(linha,coluna);
        for(int l=0; l < linha ; l++){
            for(int c=0; c < coluna; c++){
                int elemento =  QInputDialog::getInt(this , "Leitura",
                                "Matriz A [ "+ QString::number(l) + ", "+
                                QString::number(c) + "] = ");
                matB->setElemento(elemento,l,c);
            }
        }
        ui->textEditSaidaMatB->setText(matB->getMatriz());
        ui->lineEditQuantidadeColunasMatB->setEnabled(false);
        ui->lineEditQuantidadeLinhasMatB->setEnabled(false);
        ui->pushButtonCriarMatB->setEnabled(false);
        ui->pushButtonApagarMatB->setEnabled(true);
    }
    catch(std::bad_alloc&){
        QMessageBox::information(this,"ERRO NO SISTEMA","Matriz nao pode ser criada");
    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }
}

void MainWindow::on_pushButtonApagarMatB_clicked()
{
    if(matB) delete matB;
    matB = 0;
    ui->lineEditQuantidadeColunasMatB->clear();
    ui->lineEditQuantidadeLinhasMatB->clear();
    ui->textEditSaidaMatB->clear();
    ui->lineEditQuantidadeColunasMatB->setEnabled(true);
    ui->lineEditQuantidadeLinhasMatB->setEnabled(true);
    ui->pushButtonCriarMatB->setEnabled(true);
    ui->pushButtonApagarMatB->setEnabled(false);
}

//void MainWindow::on_pushButton_clicked()
//{
//}
void MainWindow::on_pushButtonAdicionar_clicked()
{
    try {
        if(matA==0) throw QString("Operação de + não pode ser executada.");
        if(matB==0) throw QString("Operação de + não pode ser executada.");
        ejm::Matriz *matC = matA->adicionar(matB);
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;
    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }
}



void MainWindow::on_pushButtonSubtrair_clicked()
{
    try {
        if(matA==0) throw QString("Operação de - não pode ser executada.");
        if(matB==0) throw QString("Operação de - não pode ser executada.");
        ejm::Matriz *matC = matA->subtrair(matB);
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;
    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }

}


void MainWindow::on_pushButtonMultiplicar_clicked()
{
    try {
        if(matA==0) throw QString("Operação de x não pode ser executada.");
        if(matB==0) throw QString("Operação de x não pode ser executada.");
        ejm::Matriz *matC = matA->multiplicar(matB);
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;
    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonTransposta1_clicked()
{
    try {
        if(matA==0) throw QString("Transposição não pode ser executada.");

        ejm::Matriz *matC = matA->transposta();
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;
    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonTransposta2_clicked()
{
    try {
        if(matB==0) throw QString("Transposição não pode ser executada.");

        ejm::Matriz *matC = matB->transposta();
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;
    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }

}

