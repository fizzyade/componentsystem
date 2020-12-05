/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of the Nedrysoft component system (https://github.com/fizzyade/componentsystem)
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

#ifndef NEDRYSOFT_COMPONENTSYSTEM_COMPONENTVIEWERDIALOG_H
#define NEDRYSOFT_COMPONENTSYSTEM_COMPONENTVIEWERDIALOG_H

#include "ComponentSystemSpec.h"

#include <QDialog>
#include <QTreeWidgetItem>

namespace Nedrysoft::ComponentSystem {
    namespace Ui {
        class ComponentViewerDialog;
    }

    /**
     * @brief       ComponentViewerDialog
     *
     * @brief       Dialog that shows the list of components detected by the
     *              system (although not necessarily loaded).  Allows further
     *              detailed information to be displayed.
     *
     */
    class COMPONENT_SYSTEM_DLLSPEC ComponentViewerDialog :
            public QDialog {

        private:
            Q_OBJECT

        public:
            /**
             * @brief       Constructor
             *
             * @param[in]   parent      parent widget
             *
             */
            explicit ComponentViewerDialog(QWidget *parent = nullptr);

            /**
             * @brief       Destructor
             *
             */
            ~ComponentViewerDialog();

            /**
             * @brief       Gets the list of disabled components
             *
             * @details     The dialog allows components to be enabled and disabled from being loaded at the
             *              next startup of the software.  This function returns a list of disabled components
             *              in a reverse domain name format which should be stored and queried by the loader
             *              at startup.
             *
             * @return      the list of disabled components
             *
             */
            QStringList disabledComponents();

        private:

            /**
             * @brief       Component List double click handler
             *
             * @details     Opens the ComponentDetailsDialog for the given component that has been double clicked.
             *
             * @param[in]   item        the item that was double clicked
             * @param[in]   column      the column that was double clicked
             */
            Q_SLOT void on_componentsTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

        private:
            Ui::ComponentViewerDialog *ui;                              //! The generated ui class for the dialog
    };
}

#endif // NEDRYSOFT_COMPONENTSYSTEM_COMPONENTVIEWERDIALOG_H