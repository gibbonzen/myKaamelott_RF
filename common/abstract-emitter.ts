import { NetworkNode } from "./network-node";
import { Emitter } from "./emitter";

export abstract class AbstractEmitter implements NetworkNode, Emitter {
    ID: number;
    
    constructor(ID: number, [parameters]) {
        this.ID = ID
    }

    emit() {
        console.log(`Node ${this.ID} emit something...`)
    }
}