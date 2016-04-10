#pragma once

#include <functional>
#include <cstddef>
#include <memory>
#include <vector>
#include <chrono>

namespace photon {

struct ExchangeData;

struct TmStatus {
    unsigned componentNumber;
    unsigned messageNumber;
    std::vector<uint8_t> payload;
};

struct TmEvent {
    unsigned componentNumber;
    unsigned messageNumber;
    unsigned eventNumber;
    std::chrono::steady_clock::time_point time;
    std::vector<uint8_t> payload;
};

struct Command {
    std::size_t componentNumber;
    std::size_t commandNumber;
    std::vector<uint8_t> payload;
};

class ExchangeHandler {
public:
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
