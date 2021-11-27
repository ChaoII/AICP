#include "dbhelper.h"

DbHelper::DbHelper(QObject *parent) : QObject(parent)
{
    mStrConnection = QString("sqlite_DbHelper");
}

DbHelper::~DbHelper()
{
    unintDB();
}

int DbHelper::initDB(const QString &dbFileName) noexcept
{
    /// 1. 字符串为空
    if ((dbFileName.isNull()) || (dbFileName.isEmpty()) )
        return -2;
    /// 2..文件不存在
    QFile dbFile(dbFileName);
    if (!dbFile.exists())
        return -3;
    mDBFileName =dbFileName;

    /// 2.5 断开先前的连接
    unintDB();
    /// 3. 连接数据库
    if (QSqlDatabase::contains(mStrConnection))
    {
        mSqlDatabase = QSqlDatabase::database(mStrConnection);
    }
    else
    {
        mSqlDatabase = QSqlDatabase::addDatabase("QSQLITE", mStrConnection);
        mSqlDatabase.setDatabaseName(mDBFileName);
        mSqlDatabase.setUserName("admin");
        mSqlDatabase.setPassword("123456");
    }
    /// 4.设置数据库名


    /// 打开数据库
    if (!mSqlDatabase.open())
        return -5;
    if (nullptr != mSqlQuery)
    {
        delete mSqlQuery;
        mSqlQuery = nullptr;
    }

    /// 打开成功
    return 0;

}

QSqlQuery *DbHelper::getRecord(const QString &tableName)
{
    /// 1. 字符串为空
    if ((tableName.isNull()) || (tableName.isEmpty()) )
    {
        //            str_err = QString("the parameter [str_table_name] is null");
        return nullptr;
    }

    /// 2. 数据库没有打开
    if (!mSqlDatabase.isOpen())
    {
        //            str_err = QString("failure, the database didn't open");
        return nullptr;
    }

    if (nullptr == mSqlQuery)
    {
        //            str_err = QString("failure, db file is openned, but the /*QSqlQuery*/ object created failure");
        return nullptr;
    }
    /// 3.构建sql语句、执行，并返回结果
    QString str_sql = QString("SELECT * FROM ") + tableName;
    mSqlQuery->prepare(str_sql);
    if (!mSqlQuery->exec())
    {
        qDebug()<<mSqlDatabase.lastError()<<mSqlQuery->lastError();
        return nullptr;
    }

    return mSqlQuery;
}

QSqlQuery DbHelper::execSelect(const QString &strSql,bool& isOk)
{
    /// 1. 字符串为空
    QSqlQuery sqlQuery(mSqlDatabase);
    sqlQuery.prepare(strSql);
    isOk = true;
    if(!sqlQuery.exec()) {
        qDebug()<<sqlQuery.lastError()<<strSql;
        isOk=false;
    };
    return sqlQuery;
}

bool DbHelper::execInsert(const QString &insertSql)
{
    QSqlQuery sqlQuery(mSqlDatabase);
    sqlQuery.prepare(insertSql);
    if(!sqlQuery.exec()){
        qDebug()<<sqlQuery.lastError()<<insertSql;
        return false;
    }
    return true;
}

bool DbHelper::execDelete(const QString &delete_sql)
{
    QSqlQuery sqlQuery(mSqlDatabase);
    sqlQuery.exec("PRAGMA foreign_keys = ON");
    sqlQuery.prepare(delete_sql);
    if(!sqlQuery.exec()){
        qDebug()<<sqlQuery.lastError()<<delete_sql;
        return false;
    }
    return true;
}

void DbHelper::unintDB()
{
    try
    {
        if (nullptr != mSqlQuery)
        {
            mSqlQuery->clear();
            delete mSqlQuery;
            mSqlQuery = nullptr;
        }

        if (mSqlDatabase.isOpen())
            mSqlDatabase.close();
    }
    catch(...)
    {
        /// take the exception and do not expand
    }
}

QSqlQuery *DbHelper::getSqlQuery()
{
    return mSqlQuery;
}


QString DbHelper::getDBFileName()
{
    return mDBFileName;
}

