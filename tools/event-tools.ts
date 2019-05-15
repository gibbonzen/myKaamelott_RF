import { NetworkEvent } from "../common/event/network-event";
import { NetworkNode } from "../common/node/network-node";

export class EventTools {

    static isReceiver(event: NetworkEvent, node: NetworkNode): boolean {
        return event.receiver.ID === node.ID
    }

}