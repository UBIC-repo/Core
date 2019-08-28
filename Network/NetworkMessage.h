
#ifndef SOCKETB_NETWORKMESSAGE_H
#define SOCKETB_NETWORKMESSAGE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <boost/asio/ip/tcp.hpp>
#include "../streams.h"
#include "../Tools/Hexdump.h"
#include "../ChainParams.h"
#include "../Tools/Log.h"

using boost::asio::ip::tcp;

typedef std::string ip_t; // ip type

class NetworkMessage {
public:
    NetworkMessage(const NetworkMessage &other) {
            if(other.data_ == nullptr || sizeof(other.data_) == 0) {
                return;
            }

            this->data_ = (char*)malloc(header_length + other.body_length_);
            this->body_length_ = other.body_length_;
            std::memcpy(this->data_, other.data_, header_length + other.body_length_);
    };

    NetworkMessage& operator=( const NetworkMessage &other ) {
        this->data_ = (char*)malloc(header_length + other.body_length_);
        this->body_length_ = other.body_length_;
        std::memcpy(this->data_, other.data_, header_length + other.body_length_);
        return *this;
    };

    uint32_t body_length_;

    char* data_;
    const static uint8_t header_length = 4;

    NetworkMessage()
            : body_length_(0)
    {
        data_ = (char*)malloc(header_length + MAX_NETWORK_MESSAGE_SIZE);
    }
    
    NetworkMessage(size_t dataSize)
            : body_length_(0)
    {
        data_ = (char*)malloc(dataSize);
    }

    ~NetworkMessage()
    {
        free(data_);
        data_ = nullptr;
    }

    char* data()
    {
        return data_;
    }

    std::size_t length() const
    {
        return header_length + body_length_;
    }

    char* body()
    {
        return data_ + header_length;
    }

    std::size_t body_length() const
    {
        return body_length_;
    }

    void body_length(std::size_t new_length)
    {
        body_length_ = (uint32_t)new_length;
        if (body_length_ > MAX_NETWORK_MESSAGE_SIZE)
            body_length_ = MAX_NETWORK_MESSAGE_SIZE;
    }

    bool decode_header()
    {
        char header[header_length + 1] = "";
        if(data_ == nullptr) {
            return false;
        }
        std::memcpy(header, data_, header_length);

        CDataStream s(SER_DISK, 1);
        s.write(header, header_length);
        s >> body_length_;

        if (body_length_ > MAX_NETWORK_MESSAGE_SIZE)
        {
            body_length_ = 0;
            return false;
        }
        return true;
    }

    void encode_header()
    {
        CDataStream s(SER_DISK, 1);
        s << body_length_;
        std::memcpy(data_, s.data(), header_length);
    }

};

class NetworkMessageHelper {
public:
    template < typename Serializable >
    static NetworkMessage serializeToNetworkMessage(Serializable data) {

        CDataStream s(SER_DISK, 1);
        s << data;

        NetworkMessage* msg = new NetworkMessage(s.size() + NetworkMessage::header_length);

        msg->body_length(s.size());
        std::memcpy(msg->body(), s.data(), msg->body_length());
        msg->encode_header();
        s.clear();

        return *msg;
    }
};

class PeerInterface {
public:
    virtual ip_t getIp() = 0;
    virtual void deliver(NetworkMessage msg) = 0;
    virtual uint32_t getBlockHeight() = 0;
    virtual void setBlockHeight(uint32_t blockHeight) = 0;
    virtual void close() = 0;
    virtual void do_connect() = 0;
    virtual std::string getDonationAddress() = 0;
    virtual void setDonationAddress(std::string donationAddress) = 0;
    virtual uint64_t getLastAsked() = 0;
    virtual void setLastAsked(uint64_t lastAsked) = 0;
    virtual void setVersion(uint16_t version) = 0;
    virtual uint16_t getVersion() = 0;
};


#endif //SOCKETB_NETWORKMESSAGE_H
