import { NetworkEvent } from "../event/network-event";

export interface Emitter {
    emit: (event: NetworkEvent) => void
}