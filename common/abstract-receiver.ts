import { NetworkNode } from "./network-node";
import { Receiver } from "./receiver";
import { Logger } from "../tools/logger";

export abstract class AbstractReceiver implements NetworkNode, Receiver {
    ID: number;

    private logger: Logger
    
    constructor(ID: number, [parameters]) {
        this.ID = ID
        this.logger = new Logger(this.toString())
    }
    
    listen() {
        this.logger.log(`Node ${this.ID} receive something...`)
    }
    
}