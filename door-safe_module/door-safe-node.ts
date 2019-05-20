import { NetworkNode } from "../common/node/network-node";
import { RadioEmitter } from "../common/emitter/radio-emitter";
import { uint8_t } from "../tools/uint8_t";

export class DoorSafeNode extends RadioEmitter implements NetworkNode {
    ID: uint8_t
    
    constructor(ID: number) {
        super()
        this.ID = new uint8_t(ID)
    }
    
}