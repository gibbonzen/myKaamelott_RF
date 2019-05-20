import { NetworkEvent } from "./network-event";
import { NetworkNode } from "../node/network-node";

export class WifiEvent implements NetworkEvent {
    emitter: NetworkNode
    receiver: NetworkNode;
    data: any[];

    constructor(emitter: NetworkNode, receiver: NetworkNode, data?: any[]) {
        this.emitter = emitter
        this.receiver = receiver
        this.data = data
    }

}