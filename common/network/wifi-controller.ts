import { Receiver } from "../receiver/receiver";
import { Emitter } from "../emitter/emitter";
import { NetworkEvent } from "../event/network-event";
import { ProtocoleWifi } from "./protocole-wifi";
import { WifiEvent } from "../event/wifi-event";

export abstract class WifiController implements Emitter, Receiver {
    network: ProtocoleWifi
    
    onEvent(event: NetworkEvent): void {
        this.onWifiEvent(event)
    }
    
    abstract onWifiEvent(event: WifiEvent): void
    
    setWifiNetwork(network: ProtocoleWifi): void {
        this.network = network
        this.network.subscribe(this)
    }
    
    emit(event: NetworkEvent): void {
        this.network.emit(event)
    }
    
}