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

#include "panelicon.h"

QIcon PanelIcon::fromTheme(const QString& iconName, const QIcon& fallback) {
    return QIcon::fromTheme(iconName, fallback);
}

QIcon PanelIcon::fromTheme(const QString& iconName,
                           const QString &fallbackIcon1,
                           const QString &fallbackIcon2,
                           const QString &fallbackIcon3,
                           const QString &fallbackIcon4) {
    return QIcon::fromTheme(iconName);
}

QIcon PanelIcon::fromTheme(const QStringList& iconNames, const QIcon& fallback) {
    return QIcon::fromTheme(iconNames.first(), fallback);
}

QIcon PanelIcon::fromSystemTheme(const QString& iconName, const QIcon& fallback) {
    restoreToSystemTheme();
    QIcon icon = QIcon::fromTheme(iconName, fallback);
    setToPanelTheme();
    return icon;
}

QIcon PanelIcon::defaultApplicationIcon() {
    return QIcon::fromTheme("application-x-executable");
}

QIcon PanelIcon::ofDesktopFile(const XdgDesktopFile& desktopFile, const QIcon& fallback) {
    QIcon icon = fromTheme(desktopFile.iconName(), fallback);
    if(icon.isNull()) {
        icon = defaultApplicationIcon();
    }
    return icon;
}

QString PanelIcon::themeName() {
    return panelIconThemeName;
}

QString PanelIcon::panelIconThemeName;
QString PanelIcon::systemIconThemeName;

void PanelIcon::setThemeName(const QString& themeName) {
    systemIconThemeName = QIcon::themeName();
    panelIconThemeName = themeName;
    QIcon::setThemeName(panelIconThemeName);
}

void PanelIcon::setToPanelTheme() {
    if(!panelIconThemeName.isEmpty()) {
        QIcon::setThemeName(panelIconThemeName);
    }
}

void PanelIcon::restoreToSystemTheme() {
    QIcon::setThemeName(systemIconThemeName);
}

