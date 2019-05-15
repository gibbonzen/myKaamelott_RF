import { NetworkNode } from "../common/node/network-node";
import { RadioEvent } from "../common/event/radio-event";
import { RadioController } from "../common/network/radio-controller";
import { Logger, Color } from "../tools/logger";
import { uint8_t } from "../tools/uint8_t";

/**
 * Communication node for receive and emit command by WiFi or RF
 */
export class MasterNode extends RadioController implements NetworkNode {
    ID: uint8_t
    
    constructor(ID: number) {
        super()
        this.ID = new uint8_t(ID)
    }
    
    onRadioEvent(event: RadioEvent): void {
        if(event.emitter == this) return
        Logger.log(`<Node n°${this.ID}> receive new event.\n`)
        Logger.log(`  Data : [${event.data}]`, this, Color.FG_BLUE_LIGHT)
    }

    emitOnRadio(event: RadioEvent): void {
        this.emit(event)
    }

}
