#ifndef OUTLINER_H
#define OUTLINER_H

#include <QWidget>
#include <QItemSelection>
class QGroupBox;
class QPushButton;
class QVBoxLayout;
class QStringListModel;
class QListView;
class QComboBox;
class Presenter;

class Outliner:public QWidget
{
    Q_OBJECT
public:
    Outliner(QWidget *parent = nullptr);
    ~Outliner();
    void SetModelListView(QStringListModel *model);
    void SetModelComboBox(QStringListModel *model);
signals:
    void signal_buttonDelClicked(int indexItem);
    void signal_buttonAddClicked(int type);
    void signal_listviewSelected(int indexItem);
    void signal_listviewUnselected(int indexItem);
private:
    QListView *listview;
    QPushButton *buttonAdd;
    QPushButton *buttonDel;
    QVBoxLayout *layout;
    QComboBox *combobox;
private slots:
    void buttonAdd_clicked();
    void buttonDel_clicked();
    void listview_clicked(const QModelIndex &index);
    void combobox_clicked();
    void listview_selectionChanged(const QItemSelection & selected, const QItemSelection & deselected);
public slots:
    void slot_deselectItemListView(int indexItem);
    void slot_selectItemListView(int indexItem);
};


#endif // OUTLINER_H
