#include "scrabble.h"
#include "ui_scrabble.h"
#include "keyboard.h"
#include "fieldbutton.h"
#include <QDebug>
#include <QFont>
#include <QMessageBox>

Scrabble::Scrabble(int _countOfGamers, bool botFl, QWidget *parent) :
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
  botFlag(botFl)
{
  ui->setupUi(this);
  for (int i = 0; i < scrabble->getCount(); i++)
  {
    QLabel *label = new QLabel;
    label->setText("Gamer " + QString::number(i + 1) + ": 0");
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
        str += word[j];
        scrabble->setCell(i, j, word[j]);
        button->setText(str);
      }
    }
  scrabble->updateField();

  giveUp = new QPushButton;
  giveUp->setText("Give up!");
  ui->verticalLayout->addWidget(giveUp);
  connect(giveUp, &QPushButton::clicked, this, &Scrabble::endGame);
  giveUp->show();

  okButton = new QPushButton;
  okButton->setText("Ok");
  connect(okButton, &QPushButton::clicked, this, &Scrabble::okPressed);
  ui->verticalLayout->addWidget(okButton);
  okButton->hide();

  cancelButton = new QPushButton;
  cancelButton->setText("Cancel");
  ui->verticalLayout->addWidget(cancelButton);
  connect(cancelButton, &QPushButton::clicked, this, &Scrabble::cancelPressed);
  cancelButton->hide();
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
  if (botFlag)
    botWord->hide();
  makeUnable();
  button->setStyleSheet("background-color: rgb(175, 238, 238)");
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
  str += letter;
  button->setText(str);
  keyboard->hide();

  okButton->show();
  cancelButton->show();

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
      str += letter;
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
  vector <Cell> result = bot->nextTurn(3, scrabble->getField(), vocabulary);
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
    button->setText(QString(result[i].getCh()));
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
    msg += "Gamer " + QString::number(i + 1) + " : " + QString::number(scrabble->getScore(i)) + "\n";
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
  button->setStyleSheet("");
  newCell = make_pair(-1, -1);
  scrabble->cancelFieldChange();
  copyFromField();
  word.clear();
  cancelButton->hide();
  okButton->hide();
  makeEnable();
  enterWord = false;
  giveUp->show();
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
  buttonFrom(newCell)->setStyleSheet("");
  newCell = make_pair(-1, -1);
  scrabble->updateScore((int)newWord.size());
  int gamer = scrabble->getGamer();
  QLabel *label = scoreLabels[gamer];
  label->setText("Gamer " + QString::number(gamer + 1) + " : " + QString::number(scrabble->getScore(gamer)));  
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
    label->setText("Gamer " + QString::number(gamer + 1) + " : " + QString::number(scrabble->getScore(gamer)));
    if (scrabble->endOfGame())
    {
      endGame();
      return;
    }
  }
  scrabble->changeGamer();
  giveUp->show();
}
