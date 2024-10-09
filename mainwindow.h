#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout> //компановщик
#include <QDebug>
#include <QPropertyAnimation>

class MainWindow : public QMainWindow {
    Q_OBJECT //Макрос для поддержки системы сигналов и слотов

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void buttonClicked();
    void textEntered();

private:
    QPushButton *button;
    QPushButton *toggleButton;
    QLineEdit *inputField;
    QLabel *outputField;
};
