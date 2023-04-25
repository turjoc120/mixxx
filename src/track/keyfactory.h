#pragma once

#include <QHash>
#include <QString>
#include <QVector>

#include "proto/keys.pb.h"
#include "track/keys.h"
#include "util/types.h"

class KeyFactory {
  public:
    static Keys loadKeysFromByteArray(const QString& keysVersion,
                                      const QString& keysSubVersion,
                                      QByteArray* keysSerialized);

    static Keys makeBasicKeys(mixxx::track::io::key::ChromaticKey global_key,
                              mixxx::track::io::key::Source source);

    static Keys makeBasicKeysFromText(const QString& global_key_text,
                                      mixxx::track::io::key::Source source);

    static QString getPreferredVersion();

    static QString getPreferredSubVersion(
            const QHash<QString, QString>& extraVersionInfo);

    static Keys makePreferredKeys(
            const KeyChangeList& key_changes,
            const QHash<QString, QString>& extraVersionInfo,
            int iSampleRate,
            SINT totalFrames);
};
