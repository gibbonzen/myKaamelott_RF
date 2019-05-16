import { OpenCommand } from "./open-command";
import { CloseCommand } from "./close-command";
import { CommandFactory, RadioData } from "../common/command/command-factory";
import { RadioCommands } from "../common/node/radio-command";

export class DoorCommandFactory implements CommandFactory {
    
    create(data: RadioData) {
        switch(data.command.ID.valueOf()) {
            case RadioCommands.OPEN:
                return new OpenCommand()
            case RadioCommands.CLOSE:
                return new CloseCommand()
            default: 
                return undefined
        }
    }
}