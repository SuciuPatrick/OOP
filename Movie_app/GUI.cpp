//
// Created by Suciu Patrick on 2019-05-16.
//

#include "GUI.h"
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QFormLayout>
#include <QtCharts>
#include <QPainter>

GUI::GUI(Controller *c) : controller(c) {
    this->mainWindow();
}

void GUI::User(){

};
void GUI::Administrator() {
    QWidget *admin = new QWidget;
    admin->show();
    this->hide();
    QHBoxLayout *layout = new QHBoxLayout{admin};
    QVBoxLayout *rightLayout = new QVBoxLayout{}, *leftLayout = new QVBoxLayout{};

    QHBoxLayout *repoLayout = new QHBoxLayout{};
    this->movies = new QListWidget{};
    this->addEntities();
    repoLayout->addWidget(this->movies);
    leftLayout->addLayout(repoLayout);
    layout->addLayout(leftLayout);

    QFormLayout *inputLayout = new QFormLayout();
    this->title = new QLineEdit{};
    this->year = new QLineEdit{};
    this->numberOfLikes = new QLineEdit{};
    this->link = new QLineEdit{};
    this->genre = new QLineEdit{};

    inputLayout->addRow("Title: ",this->title);
    inputLayout->addRow("Genre: ",this->genre);
    inputLayout->addRow("Year: ",this->year);
    inputLayout->addRow("Number of likes: ",this->numberOfLikes);
    inputLayout->addRow("link: ",this->link);

    rightLayout->addLayout(inputLayout);
    layout->addLayout(rightLayout);

    this->addButton = new QPushButton{"Add"};
    this->removeButton = new QPushButton{"Remove"};
    this->updateButton = new QPushButton{"Update"};
    this->chartButton = new QPushButton{"Chart"};

    QHBoxLayout *commandsLayout = new QHBoxLayout{};
    commandsLayout->addWidget(addButton);
    commandsLayout->addWidget(removeButton);
    commandsLayout->addWidget(updateButton);
    commandsLayout->addWidget(chartButton);

    rightLayout->addLayout(commandsLayout);

    QObject::connect(addButton, &QPushButton::clicked, [this]() {this->addMovie();});
    QObject::connect(removeButton, &QPushButton::clicked, [this]() {this->removeMovie();});
    QObject::connect(removeButton, &QPushButton::clicked, [this]() {this->updateMovie();});
    QObject::connect(chartButton, &QPushButton::clicked, [this]() {this->chartMovie();});
}

void GUI::mainWindow() {
    QVBoxLayout *layout = new QVBoxLayout{this};
    QRadioButton *adminButton, *userButton;
    adminButton = new QRadioButton("Administrator", this);
    userButton = new QRadioButton("User", this);

    layout->addWidget(adminButton);
    layout->addWidget(userButton);

   // QObject::connect(adminButton, &QPushButton::clicked, this, this->Administrator());
    QObject::connect(adminButton, &QPushButton::clicked, [this]() {this->Administrator();});
    QObject::connect(userButton, &QPushButton::clicked, [this]() {this->User();});
}

void GUI::addMovie() {
    this->controller->add(Movie(this->title->text().toStdString(), this->genre->text().toStdString(), this->year->text().toInt(), this->numberOfLikes->text().toInt(), this->link->text().toStdString()));
    addEntities();
}

void GUI::removeMovie() {
    this->controller->remove(this->title->text().toStdString());
    addEntities();
}

void GUI::updateMovie() {
    this->controller->update(Movie(this->title->text().toStdString(), this->genre->text().toStdString(), this->year->text().toInt(), this->numberOfLikes->text().toInt(), this->link->text().toStdString()));
    addEntities();
}

void GUI::chartMovie() {
    QWidget *da = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout{da};
    QPieSeries *series = new QPieSeries();
    series->append("Comedy", .10);
    series->append("Horror", .50);
    series->append("Action", .30);
    series->append("Musical", .60);

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
    QPieSlice *slice3 = series->slices().at(3);
    slice3->setLabelVisible();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Movie by genre statistics.");
    chart->legend()->hide();

    QChartView  *chartView = new QChartView(chart);
    QHBoxLayout *boxChart = new QHBoxLayout{chartView};
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(600, 400);
    chartView->show();
    //layout->addLayout(boxChart);
   // da->show();
    //QHBoxLayout *layout = new QHBoxLayout{};
}

void GUI::addEntities() {
    this->clear();

    for (auto m : this->controller->getRepo()->getDa()){
        this->movies->addItem(QString::fromStdString(m.toString()));
    }
}

void GUI::clear() {
    while (this->movies->count() > 0)
        this->movies->takeItem(0);
}


GUI::~GUI() {

}
