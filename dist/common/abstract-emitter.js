"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class AbstractEmitter {
    constructor(ID, [parameters]) {
        this.ID = ID;
    }
    emit() {
        console.log(`Node ${this.ID} emit something...`);
    }
}
exports.AbstractEmitter = AbstractEmitter;
//# sourceMappingURL=abstract-emitter.js.map