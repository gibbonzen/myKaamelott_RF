"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const event_tools_1 = require("../../tools/event-tools");
class RadioEvent {
    constructor(emitter, receiver, command) {
        this.emitter = emitter;
        this.receiver = receiver;
        this.data = event_tools_1.EventTools.radioEncode(this.emitter.ID, this.receiver.ID, command);
    }
}
exports.RadioEvent = RadioEvent;
//# sourceMappingURL=radio-event.js.map