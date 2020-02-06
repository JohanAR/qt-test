#include <QtWidgets>

class SliderWithValue : public QWidget
{
  Q_OBJECT

public:
  SliderWithValue(QString labelText, int min, int max, int initial, QWidget *parent = nullptr);
  virtual ~SliderWithValue() = default;

public slots:
  void setValue(int value);

signals:
  void valueChanged(int newValue);

private slots:
  void sliderChanged(int newValue);
  void lineEditFinished();

private:
  QIntValidator *validator;
  QLineEdit *lineEdit;
  QSlider *slider;
};

class Test : public QWidget
{
  Q_OBJECT

public:
  Test();
  virtual ~Test() = default;

public slots:
  void freqChanged(int newValue);

private:
  SliderWithValue *freq;
};
