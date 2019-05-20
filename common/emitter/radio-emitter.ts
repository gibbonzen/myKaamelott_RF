import { Emitter } from "./emitter";
import { uint8_t } from "../../tools/uint8_t";
import { ProtocoleRadio } from "../network/protocole-radio";
import { RadioEvent } from "../event/radio-event";

export abstract class RadioEmitter implements Emitter {
    ID: uint8_t
    network: ProtocoleRadio

    setRadioNetwork(network: ProtocoleRadio): void {
        this.network = network
    }
    
    emit(event: RadioEvent) {
        this.network.emit(event)
    }

}