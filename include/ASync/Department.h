//
// Created by t on 08/06/25.
//

#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <QJsonObject>
#include <QString>

#include "QTMDB.h"

namespace tmdb::ASync
{
    class Department : public QObject
    {
        Q_OBJECT

    public:
        void setDeptName(const QString& i_deptName);
        QString deptName() const;
        void setJobTitles(const std::vector<QString>& i_jobTitles);
        std::vector<QString> jobTitles() const;

        Department();
        explicit Department(const QString& i_access_token);
        Department(const QString& i_access_token, const QString& i_deptName);
        ~Department() override = default;

        Department(const QJsonObject& i_json, const QString& i_access_token);
    protected:
        void parseJson(const QJsonObject& i_json, const QString& i_access_token);
    public slots:
        void loadDepartment(const QString& i_deptName);
        void loadAllDepartments();

    private slots:
        void startedLoadingDepartmentReceived();
        void finishedLoadingDepartmentReceived(void* i_data);

        void startedLoadingAllDepartmentsReceived();
        void finishedLoadingAllDepartmentsReceived(void* i_data);

    signals:
        void startedLoadingDepartment();
        void finishedLoadingDepartment(tmdb::ASync::Department* i_department);

        void startedLoadingAllDepartments();
        void finishedLoadingAllDepartments(std::vector<tmdb::ASync::Department*> i_departments);

    protected:
        QString m_deptName;
        std::vector<QString> m_jobTitles;
        aQtmdb m_q;
    };
}

#endif //DEPARTMENT_H
