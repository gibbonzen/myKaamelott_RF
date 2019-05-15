import { Receiver } from "../receiver/receiver";
import { Emitter } from "../emitter/emitter";
import { RadioEvent } from "../event/radio-event";
import { Logger, Color } from "../../tools/logger";

export class ProtocoleRadio implements Emitter, Receiver {
    private listeners: Receiver[] = []
    
    constructor() {}
    
    listen(listener: Receiver): void {
        this.listeners.push(listener)
    }
    
    emit(event: RadioEvent): void {
        Logger.log(`Emitter <${event.emitter.ID}> emit new message...`, this, Color.FG_BLUE)
        this.listeners.forEach(l => l.onEvent(event))
    }
    
    onEvent(): void {
        console.log(`Protocole radio receive new message...`)
    }

}