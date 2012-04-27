#include "dialog.h"

#include <QLayout>
#include <QLineEdit>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>

Dialog::Dialog(QString file) :
    QDialog(0), m_settings(file, QSettings::IniFormat)
{

    setLayout(new QVBoxLayout);
    QTabWidget *tabWidget = new QTabWidget;
    layout()->addWidget(tabWidget);
    foreach(QString groupHeader, m_settings.childGroups()) {
        m_settings.beginGroup(groupHeader);
        QWidget *w = new QWidget;
        QVBoxLayout *l = new QVBoxLayout;
        w->setLayout(l);
        foreach(QString item, m_settings.childKeys()) {
            QWidget *line = new QWidget;
            line->setLayout(new QHBoxLayout);
            QLabel *label = new QLabel(item);
            QLineEdit *edit = new QLineEdit;
            edit->setText(m_settings.value(item).toString());

            line->layout()->addWidget(label);
            line->layout()->addWidget(edit);
            l->addWidget(line);
        }
        l->addStretch();

        tabWidget->addTab(w, groupHeader);
        m_settings.endGroup();
    }

}

Dialog::~Dialog()
{
}
