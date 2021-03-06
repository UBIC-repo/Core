
#ifndef TX_ADDRESS_H
#define TX_ADDRESS_H

#include <cstdint>
#include "UAmount.h"
#include "Scripts/UScript.h"
#include "Serialization/streams.h"
#include "Crypto/Hash160.h"
#include "ChainParams.h"

class Address {
protected:
    UScript script;
public:
    UScript getScript();
    void setScript(UScript script);

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action) {
        READWRITE(script);
    }
};

class DscToAddressLink {
private:
    std::vector<unsigned char> dscCertificate;
    uint32_t DSCLinkedAtHeight = 0;
    std::vector<unsigned char> passportHash;
    uint32_t deactivatedAtHeight = 0;

public:
    const std::vector<unsigned char> &getDscCertificate() const {
        return dscCertificate;
    }

    void setDscCertificate(const std::vector<unsigned char> &dscCertificate) {
        DscToAddressLink::dscCertificate = dscCertificate;
    }

    uint32_t getDSCLinkedAtHeight() const {
        return DSCLinkedAtHeight;
    }

    void setDSCLinkedAtHeight(uint32_t DSCLinkedAtHeight) {
        DscToAddressLink::DSCLinkedAtHeight = DSCLinkedAtHeight;
    }

    const std::vector<unsigned char> &getPassportHash() const {
        return passportHash;
    }

    void setPassportHash(const std::vector<unsigned char> &passportHash) {
        DscToAddressLink::passportHash = passportHash;
    }

    uint32_t getDeactivatedAtHeight() const {
        return deactivatedAtHeight;
    }

    void setDeactivatedAtHeight(uint32_t deactivatedAtHeight) {
        DscToAddressLink::deactivatedAtHeight = deactivatedAtHeight;
    }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action) {
        READWRITE(dscCertificate);
        READWRITE(DSCLinkedAtHeight);
        READWRITE(passportHash);
        READWRITE(deactivatedAtHeight);
    }
};

class AddressForStore : public Address {
private:
    std::vector<DscToAddressLink> dscToAddressLinks;
    UAmount UBIdebit;
    UAmount amount;
    uint32_t nonce = 0;
    uint8_t additionalPassportScans = 0;
    uint64_t lockedUntil = 0;
public:

    UAmount getAmount() {
        return amount;
    }

    void setAmount(UAmount amount) {
        AddressForStore::amount = amount;
    }

    uint32_t getNonce() {
        return nonce;
    }

    void setNonce(uint32_t nonce) {
        AddressForStore::nonce = nonce;
    }

    UAmount getUBIdebit() {
        return UBIdebit;
    }

    void setUBIdebit(UAmount UBIdebit) {
        AddressForStore::UBIdebit = UBIdebit;
    }

    std::vector<DscToAddressLink> getDscToAddressLinks() const {
        return dscToAddressLinks;
    }

    void setDscToAddressLinks(const std::vector<DscToAddressLink> dscToAddressLinks) {
        AddressForStore::dscToAddressLinks = dscToAddressLinks;
    }

    uint8_t getAdditionalPassportScans() const {
        return additionalPassportScans;
    }

    void setAdditionalPassportScans(uint8_t additionalPassportScans) {
        AddressForStore::additionalPassportScans = additionalPassportScans;
    }

    uint64_t getLockedUntil() const {
        return lockedUntil;
    }

    void setLockedUntil(uint64_t lockedUntil) {
        AddressForStore::lockedUntil = lockedUntil;
    }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action) {
        READWRITE(nonce);
        READWRITE(script);
        READWRITE(dscToAddressLinks);
        READWRITE(UBIdebit);
        READWRITE(amount);
        READWRITE(additionalPassportScans);
        READWRITE(lockedUntil); // Timestamp field untill when the coins on the address cannot be spent (Not implemented)
    }
};

#endif //TX_ADDRESS_H
