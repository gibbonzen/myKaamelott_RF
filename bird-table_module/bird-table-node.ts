import { RadioReceiver } from "../common/receiver/radio-receiver";
import { NetworkNode } from "../common/node/network-node";
import { RadioEvent } from "../common/event/radio-event";
import { Logger, Color } from "../tools/logger";
import { uint8_t } from "../tools/uint8_t";

export class BirdTableNode extends RadioReceiver implements NetworkNode {
    ID: uint8_t

    constructor(ID: number) {
        super()
        this.ID = new uint8_t(ID)
    }

    onRadioEvent(event: RadioEvent): void {
        Logger.log(`<Node n°${this.ID}>: receive new event from <${event.emitter.ID}>.`, this, Color.FG_CYAN)
        Logger.log(`  Data: [${event.data}]`)
    }
    
}