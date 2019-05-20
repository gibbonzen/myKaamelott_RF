import { Emitter } from "../emitter/emitter";
import { Receiver } from "../receiver/receiver";
import { ProtocoleRadio } from "./protocole-radio";
import { ProtocoleWifi } from "./protocole-wifi";
import { NetworkEvent } from "../event/network-event";
import { WifiEvent } from "../event/wifi-event";
import { RadioEvent } from "../event/radio-event";

export abstract class NetworkAdapter implements Emitter, Receiver {
    radioNetwork: ProtocoleRadio
    wifiNetwork: ProtocoleWifi

    onEvent(event: NetworkEvent) {
        if(event instanceof RadioEvent)
            this.onRadioEvent(event)
        if(event instanceof WifiEvent)
            this.onWifiEvent(event)
    }
    
    setRadioNetwork(network: ProtocoleRadio) {
        this.radioNetwork = network
        this.radioNetwork.subscribe(this)
    }
    
    abstract onRadioEvent(event: RadioEvent): void

    setWifiNetwork(network: ProtocoleWifi) {
        this.wifiNetwork = network
        this.wifiNetwork.subscribe(this)
    }

    abstract onWifiEvent(event: WifiEvent): void
    
    emit(event: NetworkEvent): void {
        if(event instanceof RadioEvent) 
            this.radioNetwork.emit(event)
        if(event instanceof WifiEvent) 
            this.wifiNetwork.emit(event)
    }
    
}