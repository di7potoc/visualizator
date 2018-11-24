#include <QtWidgets>
#include "outliner.h"

Outliner::Outliner(QWidget *parent):QWidget(parent)
{
    listview = new (std::nothrow) QListView;
    listview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    listview->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
    listview->setSelectionBehavior(QAbstractItemView::SelectItems);

    layout = new (std::nothrow) QVBoxLayout;
    buttonAdd = new (std::nothrow) QPushButton("Создать");
    buttonDel = new (std::nothrow) QPushButton("Удалить");
    combobox = new (std::nothrow) QComboBox;
    bool success = connect(buttonAdd,SIGNAL(clicked()),this,SLOT(buttonAdd_clicked()));
    Q_ASSERT(success);
    success = connect(buttonDel,SIGNAL(clicked()),this,SLOT(buttonDel_clicked()));
    Q_ASSERT(success);
    success = connect(listview,&QListView::pressed,this,&Outliner::listview_clicked);
    Q_ASSERT(success);
    layout->addWidget(combobox);
    layout->addWidget(buttonAdd);
    layout->addWidget(buttonDel);
    layout->addWidget(listview);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Ignored);
    setLayout(layout);
}

Outliner::~Outliner()
{
    delete combobox;
    delete listview;
    delete buttonAdd;
    delete buttonDel;
    delete layout;
}

void Outliner::SetModelListView(QStringListModel *model)
{
    if(model != nullptr)
    {

        listview->setModel(model);
        QItemSelectionModel * selectModel = listview->selectionModel();
        bool success = connect(selectModel,&QItemSelectionModel::selectionChanged,this,&Outliner::listview_selectionChanged);
        Q_ASSERT(success);
    }
}

void Outliner::SetModelComboBox(QStringListModel *model)
{
    if(model != nullptr)
        combobox->setModel(model);
}

void Outliner::buttonAdd_clicked()
{
    int index = combobox->currentIndex();
    emit signal_buttonAddClicked(index);
}

void Outliner::buttonDel_clicked()
{
    auto listSelectedItem = listview->selectionModel()->selectedIndexes();
    if(listSelectedItem.size() > 0)
    {
        emit signal_buttonDelClicked(listSelectedItem.first().row());
    }
}

void Outliner::listview_clicked(const QModelIndex &index)
{
    emit signal_listviewSelected(index.row());
}

void Outliner::combobox_clicked()
{

}

void Outliner::listview_selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{

}

void Outliner::slot_deselectItemListView(int indexItem)
{
    auto indexes = listview->selectionModel()->selectedIndexes();
    if( !indexes.isEmpty() )
    {
        listview->selectionModel()->select(indexes.first(),QItemSelectionModel::Deselect);
    }
}

void Outliner::slot_selectItemListView(int indexItem)
{
    auto indexes = listview->selectionModel()->selectedIndexes();
    if( indexes.isEmpty() )
    {
        listview->selectionModel()->select(indexes.first(),QItemSelectionModel::Select);
    }
}
