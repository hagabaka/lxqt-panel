/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef PANELICON_H
#define PANELICON_H

#include <QIcon>
#include <QString>
#include <xdgmacros.h>
#include <XdgDesktopFile>

class QTXDG_API PanelIcon
{
public:
    static QIcon fromTheme(const QString& iconName, const QIcon& fallback = QIcon());
    static QIcon fromTheme(const QString& iconName,
                           const QString &fallbackIcon1,
                           const QString &fallbackIcon2 = QString(),
                           const QString &fallbackIcon3 = QString(),
                           const QString &fallbackIcon4 = QString());
    static QIcon fromTheme(const QStringList& iconNames, const QIcon& fallback = QIcon());
    static QIcon defaultApplicationIcon();
    static QIcon ofDesktopFile(const XdgDesktopFile &desktopFile,
                               const QIcon& fallback = QIcon());

    static QString themeName();
    static void setThemeName(const QString& themeName);

    static QIcon fromSystemTheme(const QString& iconName, const QIcon& fallback = QIcon());

protected:
    explicit PanelIcon();
    virtual ~PanelIcon();

private:
    static QString panelIconThemeName;
    static QString systemIconThemeName;

    static void setToPanelTheme();
    static void restoreToSystemTheme();
};

#endif // PANELICON_H
