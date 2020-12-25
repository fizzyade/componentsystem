/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of the Nedrysoft component system (https://github.com/fizzyade/componentsystem)
 *
 * A cross-platform plugin system for Qt applications.
 *
 * Created by Adrian Carpenter on 03/12/2020.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NEDRYSOFT_COMPONENTSYSTEM_FONTAWESOME_H
#define NEDRYSOFT_COMPONENTSYSTEM_FONTAWESOME_H

#include <QIcon>
#include <QMap>
#include <QString>

namespace Nedrysoft {
    /**
     * @brief           The FontAwesome class provides functions to use the FontAwesome library.
     */
    class FontAwesome {
        private:
            /**
             * @brief       Gets the singleton instance of the font awesome object.
             *
             * @returns     the singleton object.
             */
            static FontAwesome *getInstance();

            /**
             * @brief       Constructs a new FontAwesome instance.
             */
            FontAwesome();

        public:

            /**
             * @brief       Returns the name of the brands font.
             *
             * #returns     the name of the brands font.
             */
            static auto brandsName() -> QString;

            /**
             * @brief       Returns the name of the regular font.
             *
             * @returns     the name of the regular font.
             */
            static auto regularName() -> QString;

            /**
             * @brief       Returns the name of the solid font.
             *
             * @returns     the name of the solid font.
             */
            static auto solidName() -> QString;

            /**
             * @brief       Returns a rich text with FontAwesome glyphs.
             *
             * @details     takes a QString with tags in [fas|fab|far <glyph name>] and produces a HTML rich text
             *              which then includes the respective font awesome glyphs in
             *
             * @param[in]   string the text to convert.
             *
             * @returns     the rich text.
             */
            static auto richText(QString string) -> QString;

            /**
             * @brief       Returns a QIcon of a font awesome glyph.
             *
             * @param[in]   glyphName the name of the font awesome glyph,
             * @param[in]   pointSize the size in points of the icon.
             * @param[in]   colour the colour for the resulting icon.
             *
             * @returns     the QIcon of the FontAwesome glyph.
             */
            static auto icon(QString glyphName, int pointSize, QColor colour) -> QIcon;

        private:
            int m_brandsId;
            int m_regularId;
            int m_solidId;

            QString m_brandsName;
            QString m_regularName;
            QString m_solidName;

            QString m_styleString;

            QMap<QString, QString> m_glyphMap;
    };
}

#endif // NEDRYSOFT_COMPONENTSYSTEM_FONTAWESOME_H