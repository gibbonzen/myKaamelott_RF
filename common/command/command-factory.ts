import { uint8_t } from "../../tools/uint8_t";
import { RadioCommand } from "../node/radio-command";

export interface RadioData {
    emitter: uint8_t,
    receiver: uint8_t,
    command: RadioCommand
}

export interface CommandFactory {
    create(data: RadioData): RadioCommand
}
