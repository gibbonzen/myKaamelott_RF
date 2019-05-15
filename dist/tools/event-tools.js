"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class EventTools {
    static isReceiver(event, node) {
        return event.receiver.ID === node.ID;
    }
}
exports.EventTools = EventTools;
//# sourceMappingURL=event-tools.js.map