#include "mainwindow.h"

void MainWindow::buttonClicked() {
    QString text = inputField->text();
    outputField->setText(text);
    qDebug() << "Button clicked, text: " << text;
}

void MainWindow::textEntered() {
    QString text = inputField->text();
    outputField->setText(text);
    qDebug() << "Text entered, text: " << text;
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { //this - родитель (* на MainWindow)
    //элементы интерфейса (виджеты)
    this->resize(400, 200);

    button = new QPushButton("Send", this);
    toggleButton = new QPushButton("Toggle", this);
    toggleButton->setCheckable(true);
    inputField = new QLineEdit(this);
    outputField = new QLabel("Вывод текста", this);

    button->setStyleSheet("background-color: #3498db; color: white; font-size: 16px;");
    inputField->setStyleSheet("border: 2px solid #2ecc71; padding: 5px;");
    outputField->setStyleSheet("color: #e74c3c; font-weight: bold;");

    //размещение элементов
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(inputField);
    layout->addWidget(button);
    layout->addWidget(toggleButton);
    layout->addWidget(outputField);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    //сигналы и слотs
    connect(button, &QPushButton::clicked, this, &MainWindow::buttonClicked);
    connect(inputField, &QLineEdit::returnPressed, this, &MainWindow::textEntered);
    connect(toggleButton, &QPushButton::clicked, [this]() {
        qDebug() << "Toggle button state:" << toggleButton->isChecked();
    });

    connect(button, &QPushButton::clicked, [this]() {
        QPropertyAnimation *animation = new QPropertyAnimation(button, "geometry");
        animation->setDuration(1000);
        animation->setStartValue(QRect(button->x(), button->y(), button->width(), button->height()));
        animation->setEndValue(QRect(button->x(), button->y(), button->width(), button->height()));
        animation->start();
    });

    qDebug() << "Приложение запущено в отладочном режиме";
}

MainWindow::~MainWindow() {}

