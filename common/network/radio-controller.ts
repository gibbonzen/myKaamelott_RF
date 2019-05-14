import { Receiver } from "../receiver/receiver";
import { Emitter } from "../emitter/emitter";
import { ProtocoleRadio } from "./protocole-radio";
import { RadioEvent } from "../event/radio-event";
import { NetworkEvent } from "../event/network-event";

export abstract class RadioController implements Emitter, Receiver {
    network: ProtocoleRadio
    
    onEvent(event: NetworkEvent): void {
        this.onRadioEvent(event)
    }
    
    abstract onRadioEvent(event: RadioEvent): void
    
    setRadioNetwork(network: ProtocoleRadio): void {
        this.network = network
        this.network.listen(this)
    }
    
    emit(event: NetworkEvent): void {
        this.network.emit(event)
    }
    
}