import { RadioReceiver } from "../common/receiver/radio-receiver";
import { NetworkNode } from "../common/node/network-node";
import { RadioEvent } from "../common/event/radio-event";
import { Logger, Color } from "../tools/logger";

export class DoorNode extends RadioReceiver implements NetworkNode {
    ID: number;
    
    constructor(ID: number) {
        super()
        this.ID = ID
    }
    
    onRadioEvent(event: RadioEvent): void {
        Logger.log(`<Node n°${this.ID}>: receive new event.`, this, Color.FG_CYAN)
        Logger.log(`  - Message: ${event.msg}`)
    }


}