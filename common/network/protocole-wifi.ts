import { Emitter } from "../emitter/emitter";
import { Receiver } from "../receiver/receiver";
import { WifiEvent } from "../event/wifi-event";
import { Logger, Color } from "../../tools/logger";
import { WifiReceiver } from "../receiver/wifi-receiver";

export class ProtocoleWifi implements Emitter, Receiver {
    private listeners: Receiver[] = []
    
    constructor() {}
    
    subscribe(listener: Receiver): void {
        this.listeners.push(listener)
    }
    
    emit(event: WifiEvent): void {
        Logger.log(`Emitter <${event.emitter.ID}> emit new message...`, this, Color.FG_BLUE)
        this.listeners.forEach(l => l.onEvent(event))
    }
    
    onEvent(): void {
        console.log(`Protocole wifi receive new message...`)
    }

}