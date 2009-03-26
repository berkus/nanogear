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

#ifndef NANOGEAR_REQUEST_H
#define NANOGEAR_REQUEST_H

#include <QString>
#include <QMetaObject>
#include <QByteArray>
#include "Context.h"
#include "ClientInfo.h"
#include "Method.h"

namespace Nanogear {

/*!
 * \class Request
 * \brief This class encapsulates and abstracts a client request
 *
 * A Request object represents a client request. That is, every client, either
 * a web browser or another program, will usually include supported media types,
 * supported charset, the resource context, request method and request
 * parameters.
 *
 * It is connector's (or, in general, a Server implementation) responsiblity
 * to fill this object and pass a reference to resources methods handlers.
 *
 * Informations sent by the client (such as supported media types, character
 * encodings, etc) is encapsulated in a ClientInfo object and is read-only.
 *
 * The requested context is encapsulated by a Context object and is read-only.
 */
class Request {
public:
    Request() { qRegisterMetaType<Request>(); };

    /*!
     * A constructor used to initialize values.
     * \param m a const reference to a Method object
     * \param c a const reference to a ContextObject
     * \param cI a const reference to a ClientInfo
     */
    Request(const Method& m, const Context& c, const ClientInfo& cI = ClientInfo())
        : m_method(m), m_context(c), m_clientInfo(cI)
        { qRegisterMetaType<Request>(); }

    virtual ~Request() {}

    /*!
     * When a client makes a request it usually specifies a method. It used to
     * determine which handler should be called on a resource.
     * \return An object encapsulating a method
     */
    const Method& method() const
        { return m_method; }
    void setMethod(const Method& method)
        { m_method = method; }

    /*!
     * A client usually makes a request at a specified URI which we call
     * 'context'
     * \return The requested context
     */
    const Context& context() const
        { return m_context; }
    void setContext(const Context& context)
        { m_context = context; }

    void setClientInfo(const ClientInfo& clientInfo)
        { m_clientInfo = clientInfo; }
    /*!
     * A client usually attaches additional informations to the request, this
     * method can be used to retrieve it.
     * \return An object representing additional informations supplied by the client
     */
    const ClientInfo& clientInfo() const
        { return m_clientInfo; }

    void setBody(const QByteArray& body)
        { m_body = body; }
    /*!
     * \return The request body in raw form
     */
    const QByteArray& body() const
        { return m_body; }

private:
    Method m_method;
    Context m_context;
    ClientInfo m_clientInfo;
    QByteArray m_body;
};

}

Q_DECLARE_METATYPE(Nanogear::Request);

#endif /* NANOGEAR_REQUEST_H */
