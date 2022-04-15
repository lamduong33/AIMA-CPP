#include "../include/AIMAGUI.hpp"

class VWindow : public QWidget
{
    Q_OBJECT;
public:
    explicit VWindow(QWidget *parent = 0);
    signals:
    public slots:
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(100, 50);

    auto button = new QPushButton(&window);
    button->setText("Get started!");
    button->setToolTip("REALLY get started");
    button->setFont(QFont("Iosevka"));
    button->setGeometry(10, 10, 80, 30);
    button->setIcon(QIcon::fromTheme("face-smile"));

    window.show();

    return app.exec();
}
