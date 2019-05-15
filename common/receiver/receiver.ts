import { NetworkEvent } from "../event/network-event";
import { NetworkNode } from "../node/network-node";

export interface Receiver {
    onEvent(event: NetworkEvent)
}