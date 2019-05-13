"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const logger_1 = require("../tools/logger");
class AbstractReceiver {
    constructor(ID, [parameters]) {
        this.ID = ID;
        this.logger = new logger_1.Logger(this.toString());
    }
    listen() {
        this.logger.log(`Node ${this.ID} receive something...`);
    }
}
exports.AbstractReceiver = AbstractReceiver;
//# sourceMappingURL=abstract-receiver.js.map