import { RadioReceiver } from "../common/receiver/radio-receiver";
import { NetworkNode } from "../common/node/network-node";
import { RadioEvent } from "../common/event/radio-event";
import { Logger, Color } from "../tools/logger";
import { uint8_t } from "../tools/uint8_t";
import { EventTools } from "../tools/event-tools";

export class DoorNode extends RadioReceiver implements NetworkNode {
    ID: uint8_t
    
    constructor(ID: number) {
        super()
        this.ID = new uint8_t(ID)
    }
    
    onRadioEvent(event: RadioEvent): void {
        Logger.log(`<Node n°${this.ID}> receive new event from <${event.emitter.ID}>.`, this, Color.FG_CYAN)
        
        let data = EventTools.radioDecode(event.data)
        Logger.log('  Data: {')
        Logger.log(`    "emitter": ${data.emitter},`)
        Logger.log(`    "receiver": ${data.receiver},`)
        Logger.log('    "command": {')
        Logger.log(`      "ID": ${data.command.ID},`)
        Logger.log(`      "value": [${data.command.value}]`)
        Logger.log('    }')
        Logger.log('  }')
        
    }

}