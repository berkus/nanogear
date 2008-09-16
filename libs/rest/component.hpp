/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008 Lorenzo Villani.
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




#ifndef NANOGEAR_REST_COMPONENT_HPP
#define NANOGEAR_REST_COMPONENT_HPP

namespace std {
    template <class T> class vector<T>;
}

namespace nanogear {
namespace rest {

    
class component : public controller {
public:
    component();
    ~component();
    
    std::vector<client> clients();
    std::vector<server> servers();
    std::vector<host> hosts();
    virtual_host default_host() const;
    
    void start();
    void stop();

    void set_log(const service::log& value);
    service::log log() const;

    void set_status(const service::status& value);
    service::status status() const;
	
    
private:
    std::vector<server> m_servers;
    std::vector<client> m_clients;
    std::vector<virtual_host> m_virtual_hosts;
    service::log m_log;
    service::status m_status;
};


}
}

#endif /* NANOGEAR_REST_COMPONENT_HPP */