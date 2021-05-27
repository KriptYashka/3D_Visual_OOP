#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade.h"
#include "facadeoperationresult.h"
#include "normalizationparameters.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Facade _fasad;
    NormalizationParameters _normalizationParameters;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadFile();
    void spinModel();
    void movingModel();
    void modelToScale();
    void allButtonActivate();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
