#ifdef SALTICIDAE_CBINDINGS
#include "salticidae/msg.h"

extern "C" {

msg_t *msg_new(_opcode_t opcode, bytearray_t *_moved_payload) {
    auto res = new msg_t(opcode, *payload);
    bytearray_free(payload);
}

datastream_t *msg_get_payload(msg_t *msg) {
    return new datastream_t(msg->get_payload());
}

const _opcode_t msg_get_opcode(const msg_t *msg) {
    return msg->get_opcode();
}

void msg_free(msg_t *msg) { delete msg; }

}

#endif