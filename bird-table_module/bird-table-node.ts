import { RadioReceiver } from "../common/receiver/radio-receiver";
import { NetworkNode } from "../common/node/network-node";
import { RadioEvent } from "../common/event/radio-event";
import { Logger, Color } from "../tools/logger";
import { uint8_t } from "../tools/uint8_t";
import { EventTools } from "../tools/event-tools";
import { RadioCommand } from "../common/node/radio-command";
import { CommandRunner } from "../common/command/command-runner";
import { Command } from "../common/node/command";
import { BirdTableCommandFactory } from "./bird-table-command-factory";
import { ClassTools } from "../tools/class-tools";

export class BirdTableNode extends RadioReceiver implements NetworkNode, CommandRunner {
    ID: uint8_t
    
    constructor(ID: number) {
        super()
        this.ID = new uint8_t(ID)
    }
    
    onRadioEvent(event: RadioEvent): void {
        Logger.log(`<Node n°${this.ID}>: receive new event from <${event.emitter.ID}>.`, this, Color.FG_CYAN)
        
        let command: RadioCommand = EventTools.extractCommand(event, new BirdTableCommandFactory())
        if(this.isRunnable(command)) {
            Logger.log(`Command [${ClassTools.getObjectClass(command)}] is runnable...`, this)
        }
        else Logger.log(`Unknown command`, this)
        
    }
    
    isRunnable(command: Command): boolean {
        return command !== undefined;
    }

    run(command: Command): void {
        
    }
    
}