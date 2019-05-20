import { Receiver } from "./receiver";
import { RadioEvent } from "../event/radio-event";
import { NetworkEvent } from "../event/network-event";
import { ProtocoleRadio } from "../network/protocole-radio";
import { NetworkNode } from "../node/network-node";
import { uint8_t } from "../../tools/uint8_t";
import { EventTools } from "../../tools/event-tools";

export abstract class RadioReceiver implements Receiver, NetworkNode {
    ID: uint8_t
    network: ProtocoleRadio
    
    onEvent(event: NetworkEvent): void {
        if(!EventTools.isReceiver(event, this)) return
        this.onRadioEvent(event)
    }
    
    abstract onRadioEvent(event: RadioEvent): void

    setRadioNetwork(network: ProtocoleRadio): void {
        this.network = network
        this.network.subscribe(this)
    }

}