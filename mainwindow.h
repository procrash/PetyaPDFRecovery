#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonRecover_clicked();

    void on_pushButtonSelectFile_clicked();

private:
    Ui::MainWindow *ui;
    void recoverPDF(std::string inFilename, std::string outFilename) ;

};

#endif // MAINWINDOW_H
