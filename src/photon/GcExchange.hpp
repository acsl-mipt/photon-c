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

class Exchange {
public:
    Exchange();
    ~Exchange();

    bool acceptIncomingData(const void* data, std::size_t size);
    bool processIncomingPacket();

    bool encodeCommandPacket(const std::vector<photon::Command>& commands);
    std::size_t readEncodedCommands(void* dest, std::size_t maxSize);

    void setReceiptHandler(const std::function<void(std::size_t)>& handler);
    void setTmStatusHandler(const std::function<bool(photon::TmStatus&&)>& handler);
    void setTmEventHandler(const std::function<bool(photon::TmEvent&&)>& handler);
    void setErrorHandler(const std::function<void(std::string&&)>& handler);

private:
    std::unique_ptr<ExchangeData> _d;
};
}
