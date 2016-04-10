#pragma once

#include "photon/Packets.h"

#include <functional>
#include <cstddef>
#include <memory>
#include <vector>
#include <chrono>

namespace photon {

struct ExchangeData;

template <typename H>
struct Entity {
    H header;
    std::vector<uint8_t> payload;
};

typedef Entity<PhotonExchangePacket> ExchangePacket;
typedef Entity<PhotonAddressPacket> AddressPacket;
typedef Entity<PhotonTmStatusMessage> TmStatus;
typedef Entity<PhotonTmEventMessage> TmEvent;
typedef Entity<PhotonCommandHeader> Command;

class ExchangeHandler {
public:
    virtual void handleExchangePacket(photon::ExchangePacket&& packet);
    virtual void handleAddressPacket(photon::AddressPacket&& packet);
    virtual void handleTmStatus(photon::TmStatus&& status);
    virtual void handleTmEvent(photon::TmEvent&& event);
    virtual void handleError(std::string&& errorMessage);
};

class Exchange {
public:
    Exchange();
    ~Exchange();

    bool acceptIncomingData(const void* data, std::size_t size);
    std::size_t copyIncomingPacket(void* dest, std::size_t size);
    std::size_t incomingPacketSize() const;
    void skipIncomingPacket();
    bool processIncomingPacket();
    bool processPacket(const void* src, std::size_t size);

    bool encodeCommandPacket(const std::vector<photon::Command>& commands);
    std::size_t readEncodedCommands(void* dest, std::size_t maxSize);

    void setHandler(const std::shared_ptr<ExchangeHandler>& handler);

private:
    std::unique_ptr<ExchangeData> _d;
};
}
