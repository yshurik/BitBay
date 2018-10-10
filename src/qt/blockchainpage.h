#ifndef INFOPAGE_H
#define INFOPAGE_H

#include <QDialog>
#include <QItemDelegate>
#include "bignum.h"

namespace Ui {
    class BlockchainPage;
}

class QModelIndex;
class QTreeWidgetItem;
class BlockchainModel;

class BlockchainPage : public QDialog
{
    Q_OBJECT

public:
    explicit BlockchainPage(QWidget *parent = nullptr);
    ~BlockchainPage();

    BlockchainModel * blockchainModel() const;

private slots:
    void showChainPage();
    void showBlockPage();
    void showTxPage();
    void openBlock(uint256);
    void openBlock(const QModelIndex &);
    void openBlock(QTreeWidgetItem*,int);
    void openTx(QTreeWidgetItem*,int);
    void openTx(uint256 blockhash, uint txidx);
    void jumpToBlock();
    void openBlockFromInput();
    void updateCurrentBlockIndex();
    void scrollToCurrentBlockIndex();

private:
    Ui::BlockchainPage *ui;
    BlockchainModel *model;
    QPersistentModelIndex currentBlockIndex;
    uint256 currentBlock;
};

#endif // INFOPAGE_H
