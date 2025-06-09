//
// Created by t on 09/06/25.
//

#ifndef IMAGE_H
#define IMAGE_H
#include <QObject>
#include <QPixmap>

#include "QTMDB.h"

namespace tmdb::ASync
{
    class Image : public QObject
    {
        Q_OBJECT
    public:
        void setPixmap(const QPixmap& i_pixmap);
        void setPixmap(const QUrl& i_url);
        QPixmap pixmap() const;

        Image() = default;
        ~Image() override = default;

        public slots:
        void loadImage(const QUrl& i_url);

        signals:
        void startedLoadingImage();
        void finishedLoadingImage(tmdb::ASync::Image* i_image);


    protected:
        QPixmap getPixmapFromUrl(const QUrl& url);

        QPixmap m_pixmap;
    };
}

#endif //IMAGE_H
