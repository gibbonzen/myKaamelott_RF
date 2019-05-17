import { RadioCommand, RadioCommands } from "../common/node/radio-command";
import { uint8_t } from "../tools/uint8_t";

export class CloseCommand extends RadioCommand {

    constructor() {
        super(new uint8_t(RadioCommands.CLOSE), [])
    }
}