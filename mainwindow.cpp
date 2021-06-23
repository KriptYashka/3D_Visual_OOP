#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), _fasad(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setWindowTitle("Lab4");
    allButtonActivate(false);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::allButtonActivate(bool flag){
    /* Активация кнопок взаимодействия со сценой */
    ui->btnScale->setEnabled(flag);
    ui->btnMoveModel->setEnabled(flag);
    ui->btnRotateModel->setEnabled(flag);
    ui->btn_show->setEnabled(flag);
}

bool MainWindow::serValidNormalizationParameters(){
    /* Устанавливается нормализация. Возвращает false, если значения не корректные. */
    _normalizationParameters.min = ui->leNormMin->text().toFloat();
    _normalizationParameters.max = ui->leNormMax->text().toFloat();
    _normalizationParameters.dxStep = ui->leStepX->text().toFloat();
    _normalizationParameters.dyStep = ui->leStepY->text().toFloat();

    bool flag = true;
    if (_normalizationParameters.max <= _normalizationParameters.min ||
            abs(_normalizationParameters.max - _normalizationParameters.min) < 200 ||
            _normalizationParameters.dxStep < 1 ||
            _normalizationParameters.dyStep < 1){
        flag = false;
    }
    return flag;
}

void MainWindow::on_btn_show_clicked(){
    /* Отображает модель на сцене */
    bool flag = serValidNormalizationParameters();

    if (!flag){
        QMessageBox::warning(0, "warning", "Диапозон нормировки задан неверно!");
        QMessageBox::information(0, "Info", "Примечание: 1. Первое значение диапозона должно быть меньш второго\n2. Диапозон по модулю должет превосходить 200");
    } else {
        FacadeOperationResult res = _fasad.loadScene(fileName, _normalizationParameters);
        if (res.isSuccess()){
            ui->graphicsView->drawScene(_fasad.picture);
            allButtonActivate(true);
        } else {
            ui->graphicsView->drawScene();
            allButtonActivate(false);
        }
    }
}

void MainWindow::on_btnLoadFile_clicked(){
    /* Запоминаем путь до файла */
//    QString dialogFileName = QFileDialog::getOpenFileName(this,"Открыть модель", "", tr("Text Files (*.csv)"));
//    fileName = dialogFileName.toStdString();
    QString dialogFileName = "schools_exams.csv";
    fileName = dialogFileName.toStdString();
    ui->label_name->setText(dialogFileName);
    ui->btn_show->setDisabled(false);
}

void MainWindow::on_btnMoveModel_clicked(){
    /* Дает запрос на передвижение модели */
    _fasad.offsetScene(ui->leValueX->text().toFloat(), ui->leValueY->text().toFloat(), ui->leValueZ->text().toFloat());
    ui->graphicsView->drawScene(_fasad.picture);
}

void MainWindow::on_btnRotateModel_clicked(){
    /* Дает запрос на поворот модели */
    bool flag = serValidNormalizationParameters();
    if (flag){
        _fasad.rotateScene(ui->leValueX->text().toFloat(), ui->leValueY->text().toFloat(), ui->leValueZ->text().toFloat());
        _fasad.normalizeScene(_normalizationParameters);
        ui->graphicsView->drawScene(_fasad.picture);
    } else {
        QMessageBox::warning(0, "warning", "Диапозон нормировки задан неверно!");
    }
}

void MainWindow::on_btnScale_clicked(){
    /* Дает запрос на масштабирование модели */
    bool flag = serValidNormalizationParameters();
    if (flag){
        _fasad.normalizeScene(_normalizationParameters);
        ui->graphicsView->drawScene(_fasad.picture);
    } else {
        QMessageBox::warning(0, "warning", "Диапозон нормировки задан неверно!");
    }
}

