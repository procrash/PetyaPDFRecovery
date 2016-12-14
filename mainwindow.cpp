#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonRecover_clicked()
{

    QString fileName = this->ui->lineEditFilename->text();

    std::string strFileName = fileName.toStdString();
    strFileName.c_str();

    recoverPDF(strFileName, strFileName+"_recovered.pdf");



}

void MainWindow::recoverPDF(std::string inFilename, std::string outFilename) {
    std::ifstream is;
    std::ofstream os;

    is.open(inFilename, std::ios::binary);
    os.open(outFilename, std::ios::binary);


    os << is.rdbuf();

    os.flush();

    is.close();

    os.seekp(0,std::ios_base::beg);

    QFile file(":/PDFData");
    file.open(QFile::ReadOnly);

    QByteArray bytes = file.readAll();
    os.write(bytes.data(), bytes.length());
    os.close();
}


void MainWindow::on_pushButtonSelectFile_clicked()
{
    QFileDialog dialog;
//    dialog.setFileMode(QFileDialog::FileName);

    QString directory = "";

    int result = dialog.exec();

    if (result) {
        directory = dialog.selectedFiles()[0];
        this->ui->lineEditFilename->setText(directory);
    }


}
