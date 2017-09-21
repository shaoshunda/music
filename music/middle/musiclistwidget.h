#ifndef MIDDLELEFTSTACKWIDGET0_H
#define MIDDLELEFTSTACKWIDGET0_H

#include "base/basewidget.h"
#include "base/basepushbutton.h"
#include "player/medialist.h"
#include "musiclisttable.h"

#include <QMediaContent>
#include <QLabel>
#include <QFileInfoList>

class PlayListHeader:public BaseWidget
{
    Q_OBJECT
public:
    PlayListHeader(QWidget *parent);
    ~PlayListHeader(){}

    void updateSongCountText(int songCount);
private:
    QLabel *m_listCountInfo;

    void initLayout();
signals:
    void sig_emptyList();
    void sig_addSong();
};

class MusicListWidget: public BaseWidget
{
    Q_OBJECT
public:
    explicit MusicListWidget(QWidget *parent);
    ~MusicListWidget(){}

    /* Update table by search result. */
    void updateLocalList(QFileInfoList fileList);
    MediaList* getMediaList(){return m_playlist;}
    void setOriginState();
    void setPlayingMediaContent(QString);
    void deleteItem(int row);
private:
    MediaList *m_playlist;
    PlayListHeader *m_header;
    MusicListTable *m_table;

    void initLayout();
    void initConnection();
    void insertIntoTable(const QFileInfo&);
    void updateSongCountLabel();
signals:
    void tableClick(int,int);
    void tableLongPressed(int);
};

#endif // MIDDLELEFTSTACKWIDGET0_H
