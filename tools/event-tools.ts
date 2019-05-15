import { NetworkEvent } from "../common/event/network-event";
import { NetworkNode } from "../common/node/network-node";
import { uint8_t } from "./uint8_t";
import { RadioCommand } from "../common/node/radio-command";

export class EventTools {

    static isReceiver(event: NetworkEvent, node: NetworkNode): boolean {
        return event.receiver.ID === node.ID
    }

    static radioDecode(data: uint8_t[]): any {
        let decode = {
            "emitter": data[0],
            "receiver": data[1]
        }

        function buildCommandValue(data, from: number): uint8_t[] {
            let commandValue: uint8_t[]
            for (; from < data.length; from++) {
                commandValue = data[from]
            }
            return commandValue
        }

        let command: RadioCommand = {
            "ID": data[2],
            "value": buildCommandValue(data, 3)
        }
        decode["command"] = command
        return decode
    }

    static radioEncode(emitter: uint8_t, receiver: uint8_t, command: RadioCommand): uint8_t[] {
        let data: uint8_t[] = []
        data.push(emitter)
        data.push(receiver)
        data.push(command.ID)

        Array.prototype.push.apply(data, command.value)

        return data
    }

}