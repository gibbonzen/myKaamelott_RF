"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const events_1 = require("events");
class AbstractEmitter {
    constructor(ID, [parameters]) {
        this.ID = ID;
        this.emitter = new events_1.EventEmitter();
    }
    emit() {
        console.log(`Node ${this.ID} emit something...`);
        this.emitter.emit("emit of something");
    }
}
exports.AbstractEmitter = AbstractEmitter;
//# sourceMappingURL=abstract-emitter.js.map