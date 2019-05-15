import { uint8_t } from "../../tools/uint8_t";

export interface Command {
    ID: uint8_t
    value: uint8_t[]
}