import { Emitter } from "./emitter";
import { NetworkEvent } from "../event/network-event";
import { WifiReceiver } from "../receiver/wifi-receiver";

export abstract class WifiEmitter implements Emitter {
    abstract subscribe: (listener: WifiReceiver) => void
    abstract emit: (event: NetworkEvent) => void
}