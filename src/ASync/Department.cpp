//
// Created by t on 08/06/25.
//

#include "ASync/Department.h"
#include "ASync/QTMDB.h"

void tmdb::ASync::Department::setDeptName(const QString& i_deptName)
{
    m_deptName = i_deptName;
}

QString tmdb::ASync::Department::deptName() const
{
    return m_deptName;
}

void tmdb::ASync::Department::setJobTitles(const std::vector<QString>& i_jobTitles)
{
    m_jobTitles = i_jobTitles;
}

std::vector<QString> tmdb::ASync::Department::jobTitles() const
{
    return m_jobTitles;
}

tmdb::ASync::Department::Department() : m_q("")
{
    m_q.setParent(this);
}

tmdb::ASync::Department::Department(const QString& i_access_token, const QString& i_deptName) : m_q(
    i_access_token.toStdString())
{
    loadDepartment(i_deptName);
}

tmdb::ASync::Department* tmdb::ASync::Department::fromJSON(const QJsonObject& i_json)
{
    auto* output = new Department();
    output->setDeptName(i_json.value("dept_name").toString());
    QJsonArray jobTitlesArray = i_json.value("job_titles").toArray();
    std::vector<QString> jobTitles;
    for (const auto& item : jobTitlesArray)
    {
        jobTitles.push_back(item.toString());
    }
    output->setJobTitles(jobTitles);
    return output;
}

void tmdb::ASync::Department::loadDepartment(const QString& i_deptName)
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Department::startedLoadingDepartmentReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Department::finishedLoadingDepartmentReceived);
    emit startedLoadingDepartment();
    setDeptName(i_deptName);
    m_q.config_jobs();
}

void tmdb::ASync::Department::loadAllDepartments()
{
    connect(&m_q, &aQtmdb::startedLoadingData, this, &tmdb::ASync::Department::startedLoadingAllDepartmentsReceived);
    connect(&m_q, &aQtmdb::finishedLoadingData, this, &tmdb::ASync::Department::finishedLoadingAllDepartmentsReceived);
    emit startedLoadingAllDepartments();
    m_q.config_jobs();
}

void tmdb::ASync::Department::startedLoadingDepartmentReceived()
{
    emit startedLoadingDepartment();
}

void tmdb::ASync::Department::finishedLoadingDepartmentReceived(void* i_data)
{
    QJsonArray json = *static_cast<QJsonArray*>(i_data);
    auto department = new tmdb::ASync::Department();
    for (int i = 0; i < json.count(); i++)
    {
        if (json[i].toObject().value("dept_name").toString() == m_deptName)
        {
            department = fromJSON(json[i].toObject());
            break;
        }
    }
    emit finishedLoadingDepartment(department);
}

void tmdb::ASync::Department::startedLoadingAllDepartmentsReceived()
{
    emit startedLoadingAllDepartments();
}

void tmdb::ASync::Department::finishedLoadingAllDepartmentsReceived(void* i_data)
{
    auto jsonArray = static_cast<QJsonArray*>(i_data);
    std::vector<tmdb::ASync::Department*> departments;
    for (const auto& item : *jsonArray)
    {
        departments.push_back(fromJSON(item.toObject()));
    }
    emit finishedLoadingAllDepartments(departments);
}
