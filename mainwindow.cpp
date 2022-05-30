#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QtEndian>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnExit, &QPushButton::clicked, this, &MainWindow::exitPressed);
    connect(ui->btnHentfil , &QPushButton::clicked, this, &MainWindow::openFilePressed);
    connect(ui->btnRecord, &QPushButton::clicked, this, &MainWindow::recordPressed);
    connect(ui->btnStopRecording, &QPushButton::clicked, this, &MainWindow::stopRecordingPressed);
    connect(ui->btnSave, &QPushButton::clicked, this, &MainWindow::savePressed);
    connect(ui->btnExit, &QPushButton::clicked, this, &MainWindow::exitPressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFilePressed()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, "Hent fil", "", tr("Lydfiler (*.wav)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;
    file.seek(44);
    qDebug() << "bytes: " << file.bytesAvailable();
    char strm[4];
    for (int i = 0; i < 10; i++)
    {
        file.seek(44 + i*100);
        file.read(strm, 4);
        qDebug()<<qFromLittleEndian<quint32>((uchar*)strm);
    }
    file.close();
}

void MainWindow::recordPressed()
{

}

void MainWindow::stopRecordingPressed()
{

}

void MainWindow::playPressed()
{

}

void MainWindow::savePressed()
{

}

void MainWindow::exitPressed()
{
    close();
}

