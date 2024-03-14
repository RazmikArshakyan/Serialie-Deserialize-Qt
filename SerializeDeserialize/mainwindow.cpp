#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->serializeBtn, &QPushButton::clicked, this, &MainWindow::saveChanges);
    connect(ui->deserializeBtn, &QPushButton::clicked, this, &MainWindow::showLastSavedStudent);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::saveChanges()
{
    if (!cachedStudent)
        cachedStudent = new Student();

    QString sName = ui->nameLine->text();
    size_t sAge = ui->ageBox->text().toInt();
    QString sBirthday = ui->birthdayLine->text();

    ui->nameLine->clear();
    ui->ageBox->clear();
    ui->birthdayLine->clear();

    cachedStudent->setName(sName);
    cachedStudent->setAge(sAge);
    cachedStudent->setBirthday(sBirthday);

    QString serializedData = cachedStudent->serialize();

    QFile file("C:\\Users\\Razmik Arshakyan\\OneDrive\\Desktop\\New-Spotify-Tasks\\SerializeDeserialize\\Server.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug("Error opening file");
        return;
    }

    QTextStream output(&file);
    output << serializedData;
    file.close();
}

void MainWindow::showLastSavedStudent()
{
    QFile file("C:\\Users\\Razmik Arshakyan\\OneDrive\\Desktop\\New-Spotify-Tasks\\SerializeDeserialize\\Server.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug("Error opening file");
        return;
    }

    if (!cachedStudent) {
        file.close();
        return;
    }

    QTextStream input(&file);
    QString line = input.readLine();
    QStringList splittedData = line.split("-");

    if (splittedData.size() != 3) {
        qDebug("Invalid data");
        file.close();
        return;
    }

    ui->nameLine->setText(splittedData[0]);
    ui->ageBox->setValue(splittedData[1].toInt());
    ui->birthdayLine->setDate(QDate::fromString(splittedData[2], "yyyy-MM-dd"));
}

