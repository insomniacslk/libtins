#include <cstring>
#include <cassert>
#include "bootp.h"
#include "utils.h"


Tins::BootP::BootP() : PDU(255) {
    _vend = new uint8_t[64];
}

Tins::BootP::~BootP() {
    delete[] vend;
}

uint32_t Tins::BootP::header_size() const {
    return sizeof(bootphdr);
}

void Tins::BootP::opcode(uint8_t new_opcode) {
    _bootp.opcode = new_opcode;
}

void Tins::BootP::htype(uint8_t new_htype) {
    _bootp.htype = new_htype;
}

void Tins::BootP::hlen(uint8_t new_hlen) {
    _bootp.hlen = new_hlen;
}

void Tins::BootP::hops(uint8_t new_hops) {
    _bootp.hops = new_hops;
}

void Tins::BootP::xid(uint32_t new_xid) {
    _bootp.xid = Utils::net_to_host_l(new_xid);
}

void Tins::BootP::secs(uint16_t new_secs) {
    _bootp.secs = Utils::net_to_host_s(new_secs);
}

void Tins::BootP::padding(uint16_t new_padding) {
    _bootp.padding = Utils::net_to_host_s(new_padding);
}

void Tins::BootP::ciaddr(uint32_t new_ciaddr) {
    _bootp.ciaddr = Utils::net_to_host_l(new_ciaddr);
}

void Tins::BootP::yiaddr(uint32_t new_yiaddr) {
    _bootp.yiaddr = Utils::net_to_host_l(new_yiaddr);
}

void Tins::BootP::siaddr(uint32_t new_siaddr) {
    _bootp.siaddr = Utils::net_to_host_l(new_siaddr);
}

void Tins::BootP::giaddr(uint32_t new_giaddr) {
    _bootp.giaddr = Utils::net_to_host_l(new_giaddr);
}

void Tins::BootP::chaddr(uint8_t *new_chaddr) {
    std::memcpy(_bootp.chaddr, new_chaddr, sizeof(_bootp.chaddr));
}

void Tins::BootP::sname(uint8_t *new_sname) {
    std::memcpy(_bootp.sname, new_sname, sizeof(_bootp.sname));
}

void Tins::BootP::file(uint8_t *new_file) {
    std::memcpy(_bootp.file, new_file, sizeof(_bootp.file));
}

void Tins::BootP::vend(uint8_t *new_vend, uint32_t size) {
    delete[] _vend;
    _vend_size = size;
    _vend = new uint8_t[size];
    std::memcpy(_vend, new_vend, size);
}

void Tins::BootP::write_serialization(uint8_t *buffer, uint32_t total_sz, const PDU *parent) {
    assert(total_sz >= sizeof(bootphdr));
    std::memcpy(buffer, &_bootp, sizeof(bootphdr));
}
