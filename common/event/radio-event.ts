import { NetworkEvent } from "./network-event";
import { uint8_t } from "../../tools/uint8_t";
import { NetworkNode } from "../node/network-node";

export class RadioEvent implements NetworkEvent {
    emitter: NetworkNode
    receiver: NetworkNode
    data: uint8_t[]

    constructor(emitter: NetworkNode, receiver: NetworkNode, data: uint8_t[]) {
        this.emitter = emitter
        this.receiver = receiver
        this.data = data
    }
}