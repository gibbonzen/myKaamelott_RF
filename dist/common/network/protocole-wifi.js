"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const logger_1 = require("../../tools/logger");
class ProtocoleWifi {
    constructor() {
        this.listeners = [];
    }
    subscribe(listener) {
        this.listeners.push(listener);
    }
    emit(event) {
        logger_1.Logger.log(`Emitter <${event.emitter.ID}> emit new message...`, this, logger_1.Color.FG_BLUE);
        this.listeners.forEach(l => l.onEvent(event));
    }
    onEvent() {
        console.log(`Protocole wifi receive new message...`);
    }
}
exports.ProtocoleWifi = ProtocoleWifi;
//# sourceMappingURL=protocole-wifi.js.map