#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[]) {
    QApplication app(argc,argv);
    QLabel *label = new QLabel("Hello Wrold");
    label->setWindowTitle("MY APP");
    label->resize(400,300);

    label->show();


    return app.exec();
}
