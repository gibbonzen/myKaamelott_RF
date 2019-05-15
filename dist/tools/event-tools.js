"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class EventTools {
    static isReceiver(event, node) {
        return event.receiver.ID === node.ID;
    }
    static radioDecode(data) {
        let decode = {
            "emitter": data[0],
            "receiver": data[1]
        };
        function buildCommandValue(data, from) {
            let commandValue;
            for (; from < data.length; from++) {
                commandValue = data[from];
            }
            return commandValue;
        }
        let command = {
            "ID": data[2],
            "value": buildCommandValue(data, 3)
        };
        decode["command"] = command;
        return decode;
    }
    static radioEncode(emitter, receiver, command) {
        let data = [];
        data.push(emitter);
        data.push(receiver);
        data.push(command.ID);
        Array.prototype.push.apply(data, command.value);
        return data;
    }
}
exports.EventTools = EventTools;
//# sourceMappingURL=event-tools.js.map