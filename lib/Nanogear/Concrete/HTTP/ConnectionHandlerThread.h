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

#ifndef NANOGEAR_CONCRETE_HTTP_CONNECTIONHANDLERTHREAD_H
#define NANOGEAR_CONCRETE_HTTP_CONNECTIONHANDLERTHREAD_H

#include <QThread>
#include <QTcpSocket>

namespace Nanogear {
namespace Concrete {
namespace HTTP {

class HTTPServer;

/*!
 * \class ConnectionHandlerThread
 * \brief Handle an HTTP connection
 * \ingroup HTTP Server
 */
class ConnectionHandlerThread : public QThread {
    Q_OBJECT
public:
    ConnectionHandlerThread(int handle);

    void run();

private:
    int m_socketHandle;
    QTcpSocket m_clientSocket;
};

}
}
}

#endif // NANOGEAR_CONCRETE_HTTP_CONNECTIONHANDLERTHREAD_H
