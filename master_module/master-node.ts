import { NetworkNode } from "../common/node/network-node";
import { RadioEvent } from "../common/event/radio-event";
import { RadioController } from "../common/network/radio-controller";
import { Logger, Color } from "../tools/logger";

/**
 * Communication node for receive and emit command by WiFi or RF
 */
export class MasterNode extends RadioController implements NetworkNode {
    ID: number;
    
    constructor(ID: number) {
        super()
        this.ID = ID
    }
    
    onRadioEvent(event: RadioEvent): void {
        if(event.emitter == this) return
        Logger.log(`<Node n°${this.ID}>: receive new event.\n  - Message : ${event.msg}`, this, Color.FG_BLUE_LIGHT)
    }

    emitOnRadio(event: RadioEvent): void {
        this.emit(event)
    }

}
