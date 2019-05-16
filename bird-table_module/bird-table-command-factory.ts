import { CommandFactory, RadioData } from "../common/command/command-factory";
import { FeedCommand } from "./feed-command";
import { RadioCommands } from "../common/node/radio-command";

export class BirdTableCommandFactory implements CommandFactory {
    
    create(data: RadioData) {
        switch(data.command.ID.valueOf()) {
            case RadioCommands.FEED:
                return new FeedCommand()
            default: 
                return undefined
        }
    }
}