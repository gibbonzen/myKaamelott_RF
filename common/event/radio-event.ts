import { NetworkEvent } from "./network-event";
import { NetworkNode } from "../node/network-node";

export class RadioEvent implements NetworkEvent {
    emitter: NetworkNode
    msg: string

    constructor(emitter: NetworkNode, msg: string) {
        this.emitter = emitter
        this.msg = msg
    }
}