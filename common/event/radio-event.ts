import { NetworkEvent } from "./network-event";
import { uint8_t } from "../../tools/uint8_t";
import { NetworkNode } from "../node/network-node";
import { RadioCommand } from "../node/radio-command";
import { EventTools } from "../../tools/event-tools";

export class RadioEvent implements NetworkEvent {
    emitter: NetworkNode
    receiver: NetworkNode
    data: uint8_t[]

    constructor(emitter: NetworkNode, receiver: NetworkNode, command: RadioCommand) {
        this.emitter = emitter
        this.receiver = receiver
        
        this.data = EventTools.radioEncode(this.emitter.ID, this.receiver.ID, command)
    }
}