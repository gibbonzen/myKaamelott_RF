import { Receiver } from "./receiver";
import { NetworkNode } from "../node/network-node";
import { uint8_t } from "../../tools/uint8_t";
import { NetworkEvent } from "../event/network-event";
import { ProtocoleWifi } from "../network/protocole-wifi";
import { WifiEvent } from "../event/wifi-event";

export abstract class WifiReceiver implements Receiver, NetworkNode {
    ID: uint8_t
    network: ProtocoleWifi

    onEvent(event: NetworkEvent) {
        throw new Error("Method not implemented.");
    }

    abstract onWifiEvent(event: WifiEvent): void

    setWifiNetwork(network: ProtocoleWifi): void {
        this.network = network
        this.network.subscribe(this)
    }

}