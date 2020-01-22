#include <QtWidgets>
#include "test.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  Test testWidget;
  testWidget.show();

  return app.exec();
}
