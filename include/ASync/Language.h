//
// Created by t on 09/06/25.
//

#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <QObject>

#include "QTMDB.h"

namespace tmdb::ASync
{
    class Language : public QObject
    {
        Q_OBJECT

    public:
        void setIso6391(const QString& i_iso_639_1);
        QString iso6391() const;
        void setEnglishName(const QString& i_english_name);
        QString englishName() const;
        void setNativeName(const QString& i_native_name);
        QString nativeName() const;

        Language();
        Language(const QString& i_access_token, const QString& i_iso_639_1);
        ~Language() override = default;

        Language* fromJSON(const QJsonObject& i_json);

    public slots:
        void loadLanguage(const QString& i_iso_639_1);
        void loadAllLanguages();

    private slots:
        void startedLoadingLanguageReceived();
        void finishedLoadingLanguageReceived(void* i_data);

        void startedLoadingAllLanguagesReceived();
        void finishedLoadingAllLanguagesReceived(void* i_data);

    signals:
        void startedLoadingLanguage();
        void finishedLoadingLanguage(tmdb::ASync::Language* i_language);

        void startedLoadingAllLanguages();
        void finishedLoadingAllLanguages(std::vector<tmdb::ASync::Language*> i_languages);

    protected:
        QString m_iso_639_1;
        QString m_english_name;
        QString m_native_name;
        aQtmdb m_q;
    };
}

#endif //LANGUAGE_H
