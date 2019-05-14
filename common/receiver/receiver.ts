import { NetworkEvent } from "../event/network-event";

export interface Receiver {
    onEvent(event: NetworkEvent)
}