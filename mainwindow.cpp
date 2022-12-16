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


void MainWindow::on_pushButtonPotenciaA_clicked()
{
    try {
        if(matA==0) throw QString("Operação de potência não pode ser executada.");

        int p = ui->lineEditPotencia1->text().toInt();
        ejm::Matriz *matC = matA->potencia(p);
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;

    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonPotenciaB_clicked()
{
    try {
        if(matB==0) throw QString("Operação de potência não pode ser executada.");

        int p = ui->lineEditPotencia1->text().toInt();
        ejm::Matriz *matC = matB->potencia(p);
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;

    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }

}


void MainWindow::on_pushButtonVezesK_A_clicked()
{
    try {
        if(matA==0) throw QString("Operação por K não pode ser executada.");

        int p = ui->lineEditVezesK_A->text().toInt();
        ejm::Matriz *matC = matA->vezesK(p);
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;

    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }

}


void MainWindow::on_pushButtonExecutar_clicked()
{
    try {
        QString str1 ="SIM";
        QString str2 ="NAO";

        if(matA->triangularSup()==true){
            QTableWidgetItem *item1 =new QTableWidgetItem(str1);
            this->ui->tableWidget->setItem(0,0,item1);
        }
        else{
            QTableWidgetItem *item2 =new QTableWidgetItem(str2);
            this->ui->tableWidget->setItem(0,0,item2);
        }
        if(matB->triangularSup()==true){
            QTableWidgetItem *item3 =new QTableWidgetItem(str1);
            this->ui->tableWidget->setItem(0,1,item3);
        }
        else{
            QTableWidgetItem *item4 =new QTableWidgetItem(str2);
            this->ui->tableWidget->setItem(0,1,item4);
        }

        if(matA->eIgual(matB)==true){
            QTableWidgetItem *item5 =new QTableWidgetItem(str1);
            this->ui->tableWidget->setItem(4,0,item5);
            QTableWidgetItem *item7 =new QTableWidgetItem(str1);
            this->ui->tableWidget->setItem(4,1,item7);
        }
        else{
            QTableWidgetItem *item6 =new QTableWidgetItem(str2);
            this->ui->tableWidget->setItem(4,0,item6);
            QTableWidgetItem *item8 =new QTableWidgetItem(str2);
            this->ui->tableWidget->setItem(4,1,item8);
        }


        if(matA->simetrica()==true){
            QTableWidgetItem *item9 =new QTableWidgetItem(str1);
            this->ui->tableWidget->setItem(2,0,item9);
        }
        else{
            QTableWidgetItem *item10 =new QTableWidgetItem(str2);
            this->ui->tableWidget->setItem(2,0,item10);
        }
        if(matB->simetrica()==true){
            QTableWidgetItem *item11 =new QTableWidgetItem(str1);
            this->ui->tableWidget->setItem(2,1,item11);
        }
        else{
            QTableWidgetItem *item12 =new QTableWidgetItem(str2);
            this->ui->tableWidget->setItem(2,1,item12);
        }
        if(matA->triangularInf()==true){
            QTableWidgetItem *item13 =new QTableWidgetItem(str1);
            this->ui->tableWidget->setItem(1,0,item13);
        }
        else{
            QTableWidgetItem *item14 =new QTableWidgetItem(str2);
            this->ui->tableWidget->setItem(1,0,item14);
        }
        if(matB->triangularInf()==true){
            QTableWidgetItem *item15 =new QTableWidgetItem(str1);
            this->ui->tableWidget->setItem(1,1,item15);
        }
        else{
            QTableWidgetItem *item16 =new QTableWidgetItem(str2);
            this->ui->tableWidget->setItem(1,1,item16);
        }
        if(matA->identidade()==true){
            QTableWidgetItem *item17 =new QTableWidgetItem(str1);
            this->ui->tableWidget->setItem(3,0,item17);
        }
        else{
            QTableWidgetItem *item18 =new QTableWidgetItem(str2);
            this->ui->tableWidget->setItem(3,0,item18);
        }
        if(matB->identidade()==true){
            QTableWidgetItem *item19 =new QTableWidgetItem(str1);
            this->ui->tableWidget->setItem(3,1,item19);
        }
        else{
            QTableWidgetItem *item20 =new QTableWidgetItem(str2);
            this->ui->tableWidget->setItem(3,1,item20);
        }
    } catch (...) {
    }
}


void MainWindow::on_pushButtonVezesK_B_clicked()
{
    try {
        if(matB==0) throw QString("Operação por K não pode ser executada.");

        int p = ui->lineEditVezesK_B->text().toInt();
        ejm::Matriz *matC = matB->vezesK(p);
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;

    }
    catch(QString &erro){
        QMessageBox::information(this,"ERRO NO SISTEMA",erro);
    }

}

