//
// Created by t on 13/06/25.
//

#include <QApplication>

#include "ASync/Department.h"
#include <QJsonObject>
#include <gtest/gtest.h>
#include "ASync/QTMDB.h"

using namespace tmdb::ASync;

TEST(DepartmentASyncTests, DefaultConstructor)
{
    Department department;
    EXPECT_STREQ(department.deptName().toStdString().c_str(), "BLANK_DEPARTMENT_NAME");
    EXPECT_TRUE(department.jobTitles().empty());
}

TEST(DepartmentASyncTests, APIGetter)
{
    bool f = false;
    Department* department = new Department(std::getenv("API_KEY"));
    QObject::connect(department, &Department::finishedLoadingDepartment, [&f](Department* dep) {
        EXPECT_STREQ(dep->deptName().toStdString().c_str(), "Crew");
        EXPECT_FALSE(dep->jobTitles().empty());
        f = true;
    });
    department->loadDepartment("Crew");
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(DepartmentASyncTests, APIAllGetter)
{
    bool f = false;
    Department* department = new Department(std::getenv("API_KEY"));
    QObject::connect(department, &Department::finishedLoadingAllDepartments, [&f](std::vector<Department*> depts) {
        for (const auto& dep : depts) {
                EXPECT_FALSE(dep->jobTitles().empty());
                EXPECT_FALSE(dep->deptName().isEmpty());
        }
        f = true;
    });
    department->loadAllDepartments();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(DepartmentASyncTests, APIJSON)
{
    bool f = false;
    aQtmdb q(std::getenv("API_KEY"));
    QObject::connect(&q, &aQtmdb::finishedLoadingData, [&f](void* response) {
        QJsonArray data = *static_cast<QJsonArray*>(response);
        EXPECT_FALSE(data.isEmpty());
        for (const QJsonValue& value : data) {
            QJsonObject obj = value.toObject();
            EXPECT_TRUE(obj.contains("department"));
            EXPECT_TRUE(obj.contains("jobs"));
            if (obj["department"].toString() == "Crew") {
                EXPECT_TRUE(obj["jobs"].toArray().contains("Stunts"));
            }
        }
        f = true;
    });
    q.config_jobs();
    while (!f)
    {
        QApplication::processEvents();
    }
}

TEST(DepartmentASyncTests, setGetters)
{
    Department department;
    department.setDeptName("Art");
    department.setJobTitles({"Art Director", "Set Designer"});

    EXPECT_STREQ(department.deptName().toStdString().c_str(), "Art");
    EXPECT_EQ(department.jobTitles().size(), 2);
    EXPECT_STREQ(department.jobTitles().at(0).toStdString().c_str(), "Art Director");
    EXPECT_STREQ(department.jobTitles().at(1).toStdString().c_str(), "Set Designer");
}