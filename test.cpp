#include "test.h"
#include <iostream>

SliderWithValue::SliderWithValue(QString labelText, int min, int max, int initial, QWidget *parent)
  : QWidget(parent)
{
  QLabel *label = new QLabel(labelText);

  lineEdit = new QLineEdit();
  lineEdit->setValidator(new QIntValidator(min, max));

  slider = new QSlider(Qt::Orientation::Horizontal);
  slider->setMinimum(min);
  slider->setMaximum(max);
  setValue(initial);

  QGridLayout *layout = new QGridLayout();
  layout->addWidget(label, 0, 0, 1, -1, Qt::AlignCenter);
  layout->addWidget(lineEdit, 1, 0);
  layout->addWidget(slider, 1, 1);
  layout->setColumnStretch(0, 1);
  layout->setColumnStretch(1, 5);

  setLayout(layout);

  connect(lineEdit, &QLineEdit::editingFinished, this, &SliderWithValue::lineEditFinished);
  connect(slider, &QSlider::valueChanged, this, &SliderWithValue::sliderChanged);
}

void SliderWithValue::setValue(int value)
{
  lineEdit->setText(QString::number(value));
  slider->setValue(value);
}

void SliderWithValue::sliderChanged(int newValue)
{
  QString newText = QString::number(newValue);
  if (lineEdit->text() != newText)
  {
    lineEdit->setText(newText);
  }
  emit valueChanged(newValue);
}

void SliderWithValue::lineEditFinished()
{
  int newValue = lineEdit->text().toInt();
  if (slider->value() != newValue)
  {
    slider->setValue(newValue);
  }
}

Test::Test()
  : QWidget()
{
  freq = new SliderWithValue("test", 900, 1100, 1000);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(freq);
  layout->addStretch(1);

  setLayout(layout);

  setWindowTitle(QApplication::translate("toplevel", "Top-level widget"));

  connect(freq, &SliderWithValue::valueChanged, this, &Test::freqChanged);
}

void Test::freqChanged(int newValue)
{
  std::cout << "new value is " << newValue << std::endl;
}
