/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtScript module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL-ONLY$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSCRIPTSYNTAXCHECKRESULT_H
#define QSCRIPTSYNTAXCHECKRESULT_H

#include <QtCore/qobjectdefs.h>

#include "qscriptshareddata_p.h"

class QString;

class QScriptSyntaxCheckResultPrivate;
class Q_SCRIPT_EXPORT QScriptSyntaxCheckResult
{
public:
    enum State {
        Error,
        Intermediate,
        Valid
    };

    QScriptSyntaxCheckResult(const QScriptSyntaxCheckResult &other);
    ~QScriptSyntaxCheckResult();

    State state() const;
    int errorLineNumber() const;
    int errorColumnNumber() const;
    QString errorMessage() const;

    QScriptSyntaxCheckResult &operator=(const QScriptSyntaxCheckResult &other);

private:
    QScriptSyntaxCheckResult();
    QScriptSyntaxCheckResult(QScriptSyntaxCheckResultPrivate *d);
    QScriptSharedDataPointer<QScriptSyntaxCheckResultPrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptSyntaxCheckResult)
    friend class QScriptEngine;
    friend class QScriptEnginePrivate;
};

#endif