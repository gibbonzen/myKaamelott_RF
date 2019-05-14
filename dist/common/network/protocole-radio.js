"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const logger_1 = require("../../tools/logger");
class ProtocoleRadio {
    constructor() {
        this.listeners = [];
    }
    listen(listener) {
        this.listeners.push(listener);
    }
    emit(event) {
        logger_1.Logger.log(`Emitter ${event.emitter.ID} emit new message...`, this, logger_1.Color.FG_BLUE);
        this.listeners.forEach(l => l.onEvent(event));
    }
    onEvent() {
        console.log(`Protocole radio receive new message...`);
    }
}
exports.ProtocoleRadio = ProtocoleRadio;
//# sourceMappingURL=protocole-radio.js.map