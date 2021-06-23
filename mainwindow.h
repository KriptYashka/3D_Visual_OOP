#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade.h"
#include "facadeoperationresult.h"
#include "normalizationparameters.h"
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    string fileName;
    Facade _fasad;
    NormalizationParameters _normalizationParameters;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadFile();
    void rotateModel();
    void offsetModel();
    void modelToScale();
    void allButtonActivate(bool flag);
    void on_btn_show_clicked();
    bool serValidNormalizationParameters();

    void on_btnLoadFile_clicked();

    void on_btnMoveModel_clicked();

    void on_btnRotateModel_clicked();

    void on_btnScale_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
