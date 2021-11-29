#ifndef DBHELPER_H
#define DBHELPER_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>

class DbHelper : public QObject
{
    Q_OBJECT
public:
    explicit DbHelper(QObject *parent = nullptr);
    ~DbHelper();
    DbHelper(const DbHelper& instance) = delete;
    DbHelper(const DbHelper&& instance) = delete;
    DbHelper& operator = (const DbHelper& instance) = delete;
    DbHelper& operator = (const DbHelper&& instance) = delete;

    ///  --------------------------------------------------------------------------------
    ///  @brief: 初始化，dbFileName是数据库文件，例如： C:/demo/hello_sqlite.db3
    ///  @return - int
    ///				-0 - 成功
    ///				-2 - 失败， 参数【dbFileName】为空
    ///				-3 - 失败， 参数【dbFileName】文件不存在
    ///				-5 - 失败， 打开参数【dbFileName】的数据库失败
    ///  --------------------------------------------------------------------------------
    int initDB(const QString& dbFileName) noexcept;


    ///  --------------------------------------------------------------------------------
    ///  @brief: 查询表的数据， 如果没有调用函数 initDB, 也将返回 nullptr
    ///  @tableName - 【tableName】表的名字
    ///  @return - QSqlQuery*
    ///					nullptr - 失败， 【tableName】为空、【数据库没有打开】、执行【SELECT* FROM table_name】语句失败 中的一种
    ///					否则，成功
    ///  --------------------------------------------------------------------------------
    QSqlQuery* getRecord(const QString& tableName);


    ///  --------------------------------------------------------------------------------
    ///  @brief: 执行sql语句，这里主要用作： 修改、删除、增加，查询用函数【getRecord】
    ///  @strSql - sql语句
    ///  @return - int
    ///				-0 - 成功
    ///				-2 - 失败，参数【strSql】为空
    ///				-3 - 失败，数据库没有打开，应该先调用函数 【initDB】
    ///				-5 - 失败，执行sql语句失败，检查sql语句
    ///  --------------------------------------------------------------------------------
    QSqlQuery execSelect(const QString& strSql,bool& isOk);

    bool execInsert(const QString& insertSql);
    bool execDelete(const QString& delete_sql);


    ///  --------------------------------------------------------------------------------
    ///  @brief: 返回当前连接的数据库文件
    ///  @return - QString
    ///  --------------------------------------------------------------------------------
    QString getDBFileName();


    ///  --------------------------------------------------------------------------------
    ///  @brief: release the space at first, 可显示范调用
    ///  @return - void
    ///  --------------------------------------------------------------------------------
    void unintDB();

    QSqlQuery * getSqlQuery();


private:
    /// 当前使用的数据库文件
    QString mDBFileName;

    /// 连接字符串
    QString mStrConnection;

    ///
    QSqlDatabase mSqlDatabase;

    ///
    QSqlQuery *mSqlQuery = nullptr;

};

#endif // DBHELPER_H
