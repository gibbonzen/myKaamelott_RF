import { Receiver } from "./receiver";
import { RadioEvent } from "../event/radio-event";
import { NetworkEvent } from "../event/network-event";
import { ProtocoleRadio } from "../network/protocole-radio";

export abstract class RadioReceiver implements Receiver {
    network: ProtocoleRadio
    
    onEvent(event: NetworkEvent): void {
        this.onRadioEvent(event)
    }
    
    abstract onRadioEvent(event: RadioEvent): void

    setRadioNetwork(network: ProtocoleRadio): void {
        this.network = network
        this.network.listen(this)
    }

}