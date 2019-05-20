import { NetworkEvent } from "../event/network-event";
import { Receiver } from "../receiver/receiver";

export interface Emitter {
    emit: (event: NetworkEvent) => void
}