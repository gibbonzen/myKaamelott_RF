import { Command } from "./command";
import { uint8_t } from "../../tools/uint8_t";

export enum RadioCommands {
    OPEN = 0,
    CLOSE = 1,
    FEED = 2
}

export class RadioCommand implements Command {
    ID: uint8_t
    value: uint8_t[]

    constructor(ID: uint8_t, value: uint8_t[]) {
        this.ID = ID
        this.value = value
    }
}