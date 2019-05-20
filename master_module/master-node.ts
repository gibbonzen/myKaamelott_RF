import { NetworkNode } from "../common/node/network-node";
import { RadioEvent } from "../common/event/radio-event";
import { Logger, Color } from "../tools/logger";
import { uint8_t } from "../tools/uint8_t";
import { WifiEvent } from "../common/event/wifi-event";
import { NetworkAdapter } from "../common/network/network-adapter";
import { RadioCommand } from "../common/node/radio-command";

/**
 * Communication node for receive and emit command by WiFi or RF
 */
export class MasterNode extends NetworkAdapter implements NetworkNode {
    ID: uint8_t
    
    constructor(ID: number) {
        super()
        this.ID = new uint8_t(ID)
    }
    
    onRadioEvent(event: RadioEvent): void {
        if(event.emitter == this) return
        Logger.log(`<Node n°${this.ID}> receive new event by radio.\n`)
        Logger.log(`  Data : [${event.data}]`, this, Color.FG_BLUE_LIGHT)
    }

    emitOnRadio(event: RadioEvent): void {
        this.emit(event)
    }

    onWifiEvent(event: WifiEvent): void {
        if(event.emitter == this) return
        Logger.log(`<Node n°${this.ID}> receive new event by wifi.\n`)

        let radioEvents: RadioEvent[] = this.translateEvent(event)
        radioEvents.forEach(e => this.emitOnRadio(e))
    }
    
    emitOnWifi(event: WifiEvent): void {
        this.emit(event)
    }

    translateEvent(event: WifiEvent): RadioEvent[] {
        let events: RadioEvent[] = []
        events = event.data
            .filter(d => d instanceof RadioCommand)
            .map(c => new RadioEvent(this, event.receiver, c))
        return events
    }

}
