#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), _fasad(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    this->setWindowTitle("KriptYashka feat. OYarugin-mk collobaration");

    ui->btnScale->setEnabled(false);
    ui->btnMoveModel->setEnabled(false);
    ui->btnRotateModel->setEnabled(false);
    ui->btn_show->setEnabled(false);

    connect(ui->btnLoadFile,SIGNAL(clicked()),this,SLOT(loadFile()));
    connect(ui->btnMoveModel,SIGNAL(clicked()),this,SLOT(movingModel()));  // Передвижение
    connect(ui->btnScale,SIGNAL(clicked()),this,SLOT(modelToScale()));  // Масштабирование
    connect(ui->btnRotateModel,SIGNAL(clicked()),this,SLOT(rotateModel()));  // Поворот
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::loadFile(){
//    QString dialogFileName = QFileDialog::getOpenFileName(this,"Открыть модель", "", tr("Text Files (*.csv)"));
//    fileName = dialogFileName.toStdString();
    QString dialogFileName = "schools_exams.csv";
    fileName = dialogFileName.toStdString();
    ui->label_name->setText(dialogFileName);
    ui->btn_show->setDisabled(false);
}

void MainWindow::allButtonActivate(){
    ui->btnScale->setEnabled(true);
    ui->btnMoveModel->setEnabled(true);
    ui->btnRotateModel->setEnabled(true);
    ui->btn_show->setEnabled(true);
}

void MainWindow::rotateModel(){
    bool flag = setNormParameters();
    if (flag){
        _fasad.rotateScene(ui->leValueX->text().toFloat(), ui->leValueY->text().toFloat(), ui->leValueZ->text().toFloat());
        _fasad.normalizeScene(_normalizationParameters);
        ui->graphicsView->drawScene(_fasad._scene);
    } else {
        QMessageBox::warning(0, "warning", "Диапозон нормировки задан неверно!");
    }
}

void MainWindow::movingModel(){
    _fasad.moveScene(ui->leValueX->text().toFloat(), ui->leValueY->text().toFloat(), ui->leValueZ->text().toFloat());
    ui->graphicsView->drawScene(_fasad._scene);
}

void MainWindow::modelToScale(){
    bool flag = setNormParameters();
    if (flag){
        _fasad.normalizeScene(_normalizationParameters);
        ui->graphicsView->drawScene(_fasad._scene);
    } else {
        QMessageBox::warning(0, "warning", "Диапозон нормировки задан неверно!");
    }
}

bool MainWindow::setNormParameters(){
    /* Здесь устанавливается нормализация */
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
    bool flag = setNormParameters();

    if (!flag){
        QMessageBox::warning(0, "warning", "Диапозон нормировки задан неверно!");
        QMessageBox::information(0, "Info", "Примечание: 1. Первое значение диапозона должно быть меньш второго\n2. Диапозон по модулю должет превосходить 200");
    } else {
        _fasad.loadScene(fileName, _normalizationParameters);
        ui->graphicsView->drawScene(_fasad._scene);
        allButtonActivate();
    }
}
