import { Command } from "./command";
import { uint8_t } from "../../tools/uint8_t";

export enum RadioCommands {
    // Common commands
    SET_HOUR               = 0b00000000,
    SET_MIN                = 0b00000001,
    SET_AUTO               = 0b00000010,

    // Door command
    OPEN                    = 0b00010000,
    CLOSE                   = 0b00010001,
    STOP                    = 0b00010010,

    // Bird table command
    FEED                    = 0b00100000,
    SET_STANDARD_WEIGHT     = 0b00100010
}

export class RadioCommand implements Command {
    ID: uint8_t
    value: uint8_t[]

    constructor(ID: uint8_t, value: uint8_t[]) {
        this.ID = ID
        this.value = value
    }
}