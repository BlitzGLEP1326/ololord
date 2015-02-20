#ifndef CACHE_H
#define CACHE_H

class BTranslator;

class QByteArray;
class QLocale;

#include "global.h"
#include "controller/baseboard.h"

#include <BCoreApplication>
#include <BeQt>

#include <QList>
#include <QMap>
#include <QString>
#include <QStringList>

namespace Cache
{

struct OLOLORD_EXPORT IpBanInfo
{
    unsigned int ip;
    int level;
};

typedef void (*ClearCacheFunction)();
typedef void (*SetMaxCacheSizeFunction)(int size);
typedef QMap<QString, ClearCacheFunction> ClearCacheFunctionMap;
typedef QMap<QString, SetMaxCacheSizeFunction> SetMaxCacheSizeFunctionMap;
typedef QList<IpBanInfo> IpBanInfoList;

const int defaultDynamicFilesCacheSize = 100 * BeQt::Megabyte;
const int defaultFileInfosCacheSize = 10 * BeQt::Megabyte;
const int defaultIpBanInfoListCacheSize = 10 * BeQt::Megabyte;
const int defaultNewsCacheSize = 10 * BeQt::Megabyte;
const int defaultRulesCacheSize = 10 * BeQt::Megabyte;
const int defaultStaticFilesCacheSize = 100 * BeQt::Megabyte;
const int defaultTranslationsCacheSize = 100;

OLOLORD_EXPORT QStringList availableCacheNames();
OLOLORD_EXPORT ClearCacheFunctionMap availableClearCacheFunctions();
OLOLORD_EXPORT SetMaxCacheSizeFunctionMap availableSetMaxCacheSizeFunctions();
OLOLORD_EXPORT bool cacheDynamicFile(const QString &path, QByteArray *data);
OLOLORD_EXPORT bool cacheFileInfo(const QString &boardName, const QString &fileName, Content::BaseBoard::File *fi);
OLOLORD_EXPORT bool cacheIpBanInfoList(IpBanInfoList *list);
OLOLORD_EXPORT bool cacheNews(const QLocale &locale, QStringList *news);
OLOLORD_EXPORT bool cacheRules(const QString &prefix, const QLocale &locale, QStringList *rules);
OLOLORD_EXPORT bool cacheStaticFile(const QString &path, QByteArray *data);
OLOLORD_EXPORT bool cacheTranslator(const QString &name, const QLocale &locale, BTranslator *t);
OLOLORD_EXPORT bool clearCache(const QString &name, QString *err = 0, const QLocale &l = BCoreApplication::locale());
OLOLORD_EXPORT void clearDynamicFilesCache();
OLOLORD_EXPORT void clearFileInfosCache();
OLOLORD_EXPORT void clearIpBanInfoListCache();
OLOLORD_EXPORT void clearNewsCache();
OLOLORD_EXPORT void clearRulesCache();
OLOLORD_EXPORT void clearStaticFilesCache();
OLOLORD_EXPORT void clearTranslatorsCache();
OLOLORD_EXPORT int defaultCacheSize(const QString &name);
OLOLORD_EXPORT QByteArray *dynamicFile(const QString &path);
OLOLORD_EXPORT Content::BaseBoard::File *fileInfo(const QString &boardName, const QString &fileName);
OLOLORD_EXPORT IpBanInfoList *ipBanInfoList();
OLOLORD_EXPORT QStringList *news(const QLocale &locale);
OLOLORD_EXPORT void removeFileInfos(const QString &boardName, const QStringList &fileNames);
OLOLORD_EXPORT QStringList *rules(const QLocale &locale, const QString &prefix);
OLOLORD_EXPORT void setDynamicFilesMaxCacheSize(int size);
OLOLORD_EXPORT void setFileInfosMaxCacheSize(int size);
OLOLORD_EXPORT void setIpBanInfoListMaxCacheSize(int size);
OLOLORD_EXPORT bool setMaxCacheSize(const QString &name, int size, QString *err = 0,
                                    const QLocale &l = BCoreApplication::locale());
OLOLORD_EXPORT void setNewsMaxCacheSize(int size);
OLOLORD_EXPORT void setRulesMaxCacheSize(int size);
OLOLORD_EXPORT void setStaticFilesMaxCacheSize(int size);
OLOLORD_EXPORT void setTranslatorsMaxCacheSize(int size);
OLOLORD_EXPORT QByteArray *staticFile(const QString &path);
OLOLORD_EXPORT BTranslator *translator(const QString &name, const QLocale &locale);

}

#endif // CACHE_H
