#include "scrabble.h"
#include "ui_scrabble.h"
#include "keyboard.h"
#include "fieldbutton.h"
#include <QDebug>
#include <QFont>
#include <QMessageBox>
#include <QPainter>

Scrabble::Scrabble(int _countOfGamers, QString name, bool botFl, QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Scrabble),
  scrabble(new ScrabbleFunc(_countOfGamers)),
  botWord(nullptr),
  keyboard(nullptr),
  vocabulary(new Vocabulary),
  newCell(make_pair(-1, -1)),
  enterWord(false),
  okButton(nullptr),
  cancelButton(nullptr),
  giveUp(nullptr),
  botFlag(botFl),
  button1(new ProxyButton),
  button2(new ProxyButton),
  name(name)
{
  ui->setupUi(this);
  for (int i = 0; i < scrabble->getCount(); i++)
  {
    QLabel *label = new QLabel;
    QString gamerName = name;
    if (i > 0 && botFlag)
      gamerName = "Android";
    label->setText(gamerName + ": 0");
    ui->layoutForScores->addWidget(label, i);
    scoreLabels.push_back(label);
  }
  vocabulary->build();
  string word = vocabulary->getRandomStartWord();
  vocabulary->add(word);
  generate(word);
  if (botFl)
  {
    bot = new Bot();
    botWord = new QLabel();
    ui->layoutForScores->addWidget(botWord);
    botWord->hide();
  }
  else
    bot = nullptr;
}

void Scrabble::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
//  painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/background.jpg").scaled(size()));
  painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/peachColor.png").scaled(size()));

  QWidget::paintEvent(e);
}


Scrabble::~Scrabble()
{
  delete vocabulary;
  for (map<QPushButton *, pair<int, int> >::iterator it = pos.begin(); it != pos.end(); it++)
    delete it->first;
  for (int i = 0; i < (int)scoreLabels.size(); i++)
    delete scoreLabels[i];

  delete bot;
  delete keyboard;
  delete okButton;
  delete cancelButton;
  delete botWord;
  delete giveUp;
  delete scrabble;
  delete ui;
  delete button1;
  delete button2;
}

char bigChar(char c)
{
  if (c > 'z' || c < 'a')
    return c;
  return c - 'a' + 'A';
}

void Scrabble::generate(string word)
{
  for (int i = 0; i < Size; i++)
    for (int j = 0; j < Size; j++)
    {
      QPushButton *button = new FieldButton;
      pos[button] = make_pair(i, j);
      ui->gridLayout->addWidget(button, i, j);
      connect(button, &QPushButton::clicked, this, &Scrabble::buttonPressed);
      connect(button, &QPushButton::clicked, this, &Scrabble::buttonMarked);
      if (i == Size / 2)
      {
        QString str = "";
        str += bigChar(word[j]);
        scrabble->setCell(i, j, word[j]);
        button->setText(str);
      }
    }
  scrabble->updateField();
  ui->verticalLayout->addWidget(button1);
  button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  button1->setStyleSheet("QPushButton {border-radius: 20px; border-top: 20px transparent; border-bottom: 20px transparent; border-right: 100px transparent; border-left: 100px transparent; min-height: 1.5em; min-width: 8em; font: 100 20pt \"System\";}");

  giveUp = new QPushButton;
  giveUp->setText("Give up!");
  giveUp->setStyleSheet("QPushButton {color: white; background-color: rgb(0, 120, 150); border-radius: 20px; border-top: 20px transparent; border-bottom: 20px transparent; border-right: 100px transparent; border-left: 100px transparent; min-height: 1.5em; min-width: 8em; font: 100 20pt \"System\";}");
  ui->verticalLayout->addWidget(giveUp);
  connect(giveUp, &QPushButton::clicked, this, &Scrabble::endGame);
  giveUp->show();
  giveUp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  okButton = new QPushButton;
  okButton->setText("Ok");
  connect(okButton, &QPushButton::clicked, this, &Scrabble::okPressed);
  ui->verticalLayout->addWidget(okButton);
  okButton->setStyleSheet("QPushButton {color: white; background-color: rgb(0, 120, 150); border-radius: 20px; border-top: 20px transparent; border-bottom: 20px transparent; border-right: 100px transparent; border-left: 100px transparent; min-height: 1.5em; min-width: 8em; font: 100 20pt \"System\";}");
  okButton->hide();
  okButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  cancelButton = new QPushButton;
  cancelButton->setText("Cancel");
  cancelButton->setStyleSheet("QPushButton {color: white; background-color: rgb(0, 120, 150); border-radius: 20px; border-top: 20px transparent; border-bottom: 20px transparent; border-right: 100px transparent; border-left: 100px transparent; min-height: 1.5em; min-width: 8em; font: 100 20pt \"System\";}");
  ui->verticalLayout->addWidget(cancelButton);
  connect(cancelButton, &QPushButton::clicked, this, &Scrabble::cancelPressed);
  cancelButton->hide();
  cancelButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  ui->verticalLayout->addWidget(button2);
  button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  button2->setStyleSheet("QPushButton {border-radius: 20px; border-top: 20px transparent; border-bottom: 20px transparent; border-right: 100px transparent; border-left: 100px transparent; min-height: 1.5em; min-width: 8em; font: 100 20pt \"System\";}");
}

void Scrabble::buttonPressed()
{
  if (enterWord)
    return;
  QPushButton *button = dynamic_cast<QPushButton *>(sender());
  newCell = pos[button];
  if (scrabble->isIsolated(newCell.first, newCell.second))
    return;
  char letter = scrabble->getOldCell(newCell.first, newCell.second);
  if (letter != '\0' || letter == '!')
  {
    newCell = make_pair(-1, -1);
    return;
  }
  if (!keyboard)
  {
    keyboard = new Keyboard();
    connect(keyboard, &Keyboard::throwSignal, this, &Scrabble::letterPressed);
    ui->verticalLayout->addWidget(keyboard);
  }
  keyboard->makeEnable();
  keyboard->show();
  giveUp->hide();
  button1->hide();
  button2->hide();
  if (botFlag)
    botWord->hide();
  makeUnable();
  //button->setStyleSheet("QPushButton {background-color: rgb(155, 255, 220); border-top: 20px transparent; border-bottom: 20px transparent; border-right: 100px transparent; border-left: 100px transparent;}");
  button->setStyleSheet("background-color: rgb(175, 238, 238);");
}

void Scrabble::letterPressed()
{
  if (!keyboard)
    return;
  char letter = keyboard->getLetter();
  scrabble->setCell(newCell.first, newCell.second, letter);
  QPushButton *button = nullptr;
  for (map<QPushButton *, pair<int, int> >::iterator it = pos.begin(); it != pos.end(); it++)
    if (it->second == newCell)
    {
      button = it->first;
      break;
    }
  assert(button != nullptr);
  QString str = "";
  str += bigChar(letter);
  button->setText(str);
  keyboard->hide();

  okButton->show();
  cancelButton->show();
  button1->show();

  enterWord = true;
  makeEnable();
}

void Scrabble::copyFromField()
{
  for (map<QPushButton *, pair<int, int> >::iterator it = pos.begin(); it != pos.end(); it++)
  {
    pair<int, int> position = it->second;
    QString str = "";
    char letter = scrabble->getCell(position.first, position.second);
    if (letter != '!' && letter != '\0')
      str += bigChar(letter);
    it->first->setText(str);
  }
}

void Scrabble::makeEnable()
{
  for (map<QPushButton *, pair<int, int> >::iterator it = pos.begin(); it != pos.end(); it++)
    it->first->setEnabled(true);
}

void Scrabble::makeUnable()
{
  for (map<QPushButton *, pair<int, int> >::iterator it = pos.begin(); it != pos.end(); it++)
      it->first->setEnabled(false);
}

void Scrabble::botTurn()
{
  vector <Cell> result = bot->nextTurn(rand() % 6, scrabble->getField(), vocabulary);
  QString qWord = "";
  string sWord = "";
  for (int i = 0; i < (int)result.size(); ++i)
  {
    qWord = qWord + result[i].getCh();
    sWord += result[i].getCh();
  }
  scrabble->updateScore(result.size());
  for (int i = 0; i < (int)result.size(); ++i)
  {
    scrabble->setCell(result[i].getX(), result[i].getY(), result[i].getCh());
    QPushButton *button = buttonFrom(make_pair(result[i].getX(), result[i].getY()));
    button->setText(QString(bigChar(result[i].getCh())));
  }
  scrabble->updateField();
  vocabulary->add(sWord);
  if (botFlag)
  {
    botWord->setText("Bot word: " + qWord);
    botWord->show();
  }
}

void Scrabble::endGame()
{
  QString msg = "Game is over! Scores:\n";
  for (int i = 0; i < scrabble->getCount(); i++)
  {
    if (i == 0)
      msg += name;
    if (i > 0 && botFlag)
      msg += "Android";
    if (i > 0 && !botFlag)
      msg += name;
    msg += ": " + QString::number(scrabble->getScore(i)) + "\n";
  }
  int ok = QMessageBox::information(this, "Game over", msg);
  if (ok == QMessageBox::Ok)
    emit endOfGame();
}

QPushButton *Scrabble::buttonFrom(pair<int, int> coord)
{
  for (map<QPushButton *, pair<int, int> >::iterator it = pos.begin(); it != pos.end(); it++)
    if (it->second == coord)
      return it->first;
  return nullptr;
}

void Scrabble::cancelPressed()
{
  QPushButton *button = nullptr;
  for (map<QPushButton *, pair<int, int> >::iterator it = pos.begin(); it != pos.end(); it++)
    if (it->second == newCell)
    {
      button = it->first;
      break;
    }
  assert(button != nullptr);
  //button->setStyleSheet("QPushButton {background-color: rgb(255, 200, 210); border-top: 20px transparent; border-bottom: 20px transparent; border-right: 100px transparent; border-left: 100px transparent;}");
  button->setStyleSheet("background-color: rgb(255, 228, 225); ");
  newCell = make_pair(-1, -1);
  scrabble->cancelFieldChange();
  copyFromField();
  word.clear();
  cancelButton->hide();
  okButton->hide();
  makeEnable();
  enterWord = false;
  giveUp->show();
  button2->show();
}

void Scrabble::buttonMarked()
{
  if (!enterWord)
    return;
  QPushButton *button = dynamic_cast<QPushButton *>(sender());
  char letter = scrabble->getCell(pos[button].first, pos[button].second);
  if (letter == '\0' || letter == '!')
    return;
  if (word.size() > 0 && !scrabble->areNeigbors(word.back().first, word.back().second, pos[button].first, pos[button].second))
    return;
  for (int i = 0; i < (int)word.size(); i++)
    if (word[i] == pos[button])
      return;
  word.push_back(pos[button]);
  button->setEnabled(false);
}

void Scrabble::okPressed()
{
  string newWord = "";
  bool ok = false;
  for (int i = 0; i < (int)word.size(); i++)
  {
    ok |= (word[i] == newCell);
    newWord += scrabble->getCell(word[i].first, word[i].second);
  }
  word.clear();
  makeEnable();
  if (!ok)
  {
    QMessageBox msgBox;
    msgBox.setText("You should include new letter to the word");
    msgBox.exec();
    return;
  }
  if (!vocabulary->add(newWord))
  {
    QMessageBox msgBox;
    msgBox.setText("There is no such word or word was used before");
    msgBox.exec();
    return;
  }    
  scrabble->updateField();
  okButton->hide();
  cancelButton->hide();
  enterWord = false;
  buttonFrom(newCell)->setStyleSheet("background-color: rgb(255, 228, 225); ");
  newCell = make_pair(-1, -1);
  scrabble->updateScore((int)newWord.size());
  int gamer = scrabble->getGamer();
  QLabel *label = scoreLabels[gamer];
  QString gamerName = name;
  if (gamer > 0 && botFlag)
    gamerName = "Android";
  label->setText(gamerName + ": " + QString::number(scrabble->getScore(gamer)));
  if (scrabble->endOfGame())
  {
    endGame();
    return;
  }
  if (botFlag)
  {
    scrabble->changeGamer();
    int gamer = scrabble->getGamer();
    botTurn();
    if (scrabble->endOfGame())
    {
      endGame();
      return;
    }
    QLabel *label = scoreLabels[gamer];
    QString gamerName = name;
    if (gamer > 0 && botFlag)
      gamerName = "Android";
    label->setText(gamerName + ": " + QString::number(scrabble->getScore(gamer)));
    if (scrabble->endOfGame())
    {
      endGame();
      return;
    }
  }
  scrabble->changeGamer();
  giveUp->show();
}
