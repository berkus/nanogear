/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008-2009 Lorenzo Villani.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NANOGEAR_CLIENTINFO_H
#define NANOGEAR_CLIENTINFO_H

#include <QMetaType>
#include <QLocale>

#include "PreferenceList.h"
#include "MimeType.h"

class QTextCodec;
class QLocale;

namespace Nanogear {

/*!
 * \class ClientInfo
 * \brief Represents additional informations supplied by the client
 *
 * This class represents additional informations supplied by the client
 * such as the UserAgent, the accepted MIME types, locales and character sets.
 *
 * This data is used for content-negotiation. A resource is not forced to send
 * data back to client according to the parameters provided by ClientInfo
 * but it's highly suggested to do so.
 *
 * The data provided by this class is meant to be read-only.
 */
class ClientInfo {
public:
    /*!
     * A constructor used to initialize values.
     * This constructor is intended to be used only by 'Server' implementations
     *
     * \param mimeTypes a list of supported MIME types
     * \param locales a list of supported locales
     * \param codecs a list of supported character encodings
     * \param userAgent the UserAgent string (if any)
     */
    ClientInfo(const PreferenceList<MimeType>& mimeTypes,
        const PreferenceList<QLocale>& locales,
        const PreferenceList<QTextCodec*>& codecs,
        const QString& userAgent = QString()) : m_mimeTypes(mimeTypes),
        m_locales(locales), m_codecs(codecs), m_userAgent(userAgent) {}

    /*!
     * \return The UserAgent string (if any)
     */
    const QString& userAgent() const;

    /*!
     * \return The list of accepted MIME types
     */
    const PreferenceList<MimeType>& acceptedMimeTypes() const
        { return m_mimeTypes; }

    /*!
     * \return The list of accepted MIME types
     */
    const PreferenceList<QLocale>& acceptedLocales() const
        { return m_locales; }

    /*!
     * \return The list of accepted charsets
     */
    const PreferenceList<QTextCodec*>& acceptedTextCodecs() const
        { return m_codecs; }
private:
    PreferenceList<MimeType> m_mimeTypes;
    PreferenceList<QLocale> m_locales;
    PreferenceList<QTextCodec*> m_codecs;
    QString m_userAgent;
};

}

#endif // NANOGEAR_CLIENTINFO_H
